# -*- coding: utf-8 -*-
"""
Created on Fri Sep 13 14:48:42 2019

@author: Lucian
"""

from sed_roadrunner import model, task, plot

#----------------------------------------------

model1 = model("models/oscli.xml")
elements = ['time', 'S1', 'S2', 'J0_v0']
task1 = {}
for element in elements:
    task1[element] = [model1[element]]

for x in range(0,100):
    if(x>=40 and x < 60):
        model1.J0_v0 = 0.1
    else:
        model1.J0_v0 = 8
    model1.onestep(0.1)
    for element in elements:
        task1[element].append(model1[element])

plot(task1, "time")

