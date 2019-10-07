# -*- coding: utf-8 -*-
"""
Created on Fri Sep 13 14:48:42 2019

@author: Lucian
"""

from sed_roadrunner import model, task, plot

#----------------------------------------------

#Models:
model1 = model("models/BIOMD0000000021.xml")
model2 = model1.copy()
model2.V_mT = 0.28
model2.V_dT = 4.8

#Simulations:
task1 = model1.uniform(0, 380, 1000)
task2 = model2.uniform(0, 380, 1000)

#Plotting:
p1 = plot(task1, "time", '[Mt]', "task1 [Mt]")
p1.addPlot(task2, "time", "[Mt]", "task2 [Mt]")
p1.set_ylabel("Concentration")

p2 = plot(task1, "[Cn]", "[Mt]", "task1")
p2.addPlot(task2, "[Cn]", "[Mt]", "task2")
p2.set_ylabel("[Mt]")

#testing:
try:
    model1.unknown = 3
    print("Incorrectly set unknown element.")
except:
    print("Correctly refused to set unknown element.")

