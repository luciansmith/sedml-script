# -*- coding: utf-8 -*-
"""
Created on Tue Sep 10 14:14:57 2019

@author: Lucian
"""

from os.path import isfile
import tesbml
import roadrunner
import numpy as np
import matplotlib.pyplot as plt
#import matplotlib
#matplotlib.use('TkAgg')

class AttributeDict():
    _data = None
    knownatts = set(['knownatts', '_data'])

    def __init__(self):
        self._data = dict()
        self.knownatts = set(['knownatts', '_data'])

    def setDict(self, key, value):
        if not self._data:
            self._data = dict()
        self._data[key] = value

    def __setitem__(self, key, value):
        self.setDict(key, value)

    def __setattr__(self, key, value):
        if self._data and key in self._data:
            self.setDict(key, value)
        elif key in self.knownatts:
            super().__setattr__(key, value)
        else:
            raise Exception("Can't set the '" + key + "' attribute:  it is not known.")

    def setData(self, data):
        self._data = data

    def getDict(self, key):
        return self._data[key]

    def __getitem__(self, key):
        return self.getDict(key)

    def __getattr__(self, key):
        if key in self.__dict__:
            return self.__dict__[key]
        else:
            return self.getDict(key)

    def __repr__(self):
        return str(self._data)

    def __iter__(self):
       ''' Returns the Iterator object '''
       return self._data.__iter__()

    def keys(self):
        return self._data.keys()
    
    def values(self):
        return self._data.values()

class task(AttributeDict):
    def __init__(self, ndarray=None, names=None):
        super().__init__()
        if ndarray is not None and names is not None:
            for name in names:
                self._data[name] = ndarray[name]

class model(AttributeDict):
    doc = None
    rr = None
    outputVariables = None

    def __init__(self, string, sbml = None):
        super().__init__()
        self.knownatts.add("doc")
        self.knownatts.add("rr")
        self.knownatts.add("outputVariables")
        self.outputVariables = ['time']
        print("This is the constructor method.")
        if isfile(string):
            super().__setattr__("doc", tesbml.readSBMLFromFile(string))
            if self.doc.getModel() == None:
                raise Exception("No SBML model present at '" + string + "'.")
        elif sbml is not None:
            self.doc = sbml.clone()
        else:
            self.doc = tesbml.readSBMLFromString(string)
            if self.doc.getModel() == None:
                raise Exception("Unable to parse string as an SBML model, or file not found.")
        self.rr = roadrunner.RoadRunner(self.doc.toSBML())
        self.saveModelElements()
        self.saveRRElements()

    def setDict(self, key, value):
        self.rr[key] = value
        super().setDict(key, value)

    def copy(self):
        ret = model("", self.doc)
        return ret

    def saveModelElements(self):
        if not self.doc or not self.doc.getModel():
            return
        sbmlmod = self.doc.getModel()
        for s in range(sbmlmod.getNumSpecies()):
            species = sbmlmod.getSpecies(s)
            sid = species.getId()
            sid_conc = "[" + sid + "]"
            value = ""
            if species.isSetInitialAmount():
                value = species.getInitialAmount()
                self._data[sid] = value
            elif species.isSetInitialConcentration():
                value = species.getInitialConcentration()
                self._data[sid_conc] = value
            if species.getHasOnlySubstanceUnits():
                self.outputVariables.append(sid)
            else:
                self.outputVariables.append(sid_conc)
        for p in range(sbmlmod.getNumParameters()):
            param = sbmlmod.getParameter(p)
            pid = param.getId()
            value = ""
            if param.isSetValue():
                value = param.getValue()
            self._data[pid] = value
            if not param.getConstant():
                self.outputVariables.append(pid)
        for c in range(sbmlmod.getNumCompartments()):
            comp = sbmlmod.getCompartment(c)
            cid = comp.getId()
            value = ""
            if comp.isSetSize():
                value = comp.getSize()
            self._data[cid] = value
            if not comp.getConstant():
                self.outputVariables.append(cid)

    def saveRRElements(self):
        for element in self.rr.model.keys():
            self._data[element] = self.rr[element]

    #Functions for SED-ML Script use:
    def uniform(self, start, end, nsteps=0, step=0):
        print("Running a uniform time course from", start, "to", end)
        if nsteps<0:
            raise Exception("Unable to simulate for a negative number of steps (" + str(nsteps) + ").")
        if nsteps > 0:
            result = self.rr.simulate(start, end, steps=nsteps, selections=self.outputVariables)
        elif step > 0:
            steps = np.round((end-start)/step)
            result = self.rr.simulate(start, end, steps=steps, selections=self.outputVariables)
        else:
            result = self.rr.simulate(start, end, selections=self.outputVariables)
        self.saveRRElements()
        return task(ndarray=result, names=self.outputVariables)
    

class plot:
    def __init__(self, task=None, x=None, ys=None, labels=None):
        fig = plt.figure()
        sp = fig.add_subplot()
        self._fig = fig
        self._sp = sp
        if task is not None:
            self.addPlot(task, x, ys, labels)
        print("Creating a plot.")

    def addPlot(self, task, x=None, ys=None, labels = None):
        print("Adding a plot to an existing plot.")
        sp = self._sp
        if isinstance(ys, str):
            ys = [ys]
        if isinstance(labels, str):
            labels = [labels]
        if x is None:
            if ys is None:
                for n, y in enumerate(task):
                    label = y
                    if labels is not None:
                        label = labels[n]
                    sp.plot(task[y], label=label)
            else:
                for n, y in enumerate(ys):
                    label = y
                    if labels is not None:
                        label = labels[n]
                    sp.plot(task[y], label=label)
        else:
            xaxis = task[x]
            self._sp.set_xlabel(x)
            if ys is None:
                offset = 0
                for n, y in enumerate(task):
                    n = n - offset
                    if y==x:
                        offset = 1
                        continue
                    label = y
                    if labels is not None:
                        label = labels[n]
                    sp.plot(xaxis, task[y], label=label)
            else:
                for n, y in enumerate(ys):
                    label = y
                    if labels is not None:
                        label = labels[n]
                    sp.plot(xaxis, task[y], label=label)
        self._fig.legend()

    def show(self):
        self._fig.show()
    
    def save(self, filename):
        self._fig.savefig(filename)

    def set_xlabel(self, label):
        self._sp.set_xlabel(label)

    def set_ylabel(self, label):
        self._sp.set_ylabel(label)

