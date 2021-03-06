# -*- coding: utf-8 -*-
"""

Created by libsedmlscript v0.0.1
"""

from sed_roadrunner import model, task, plot

#----------------------------------------------

model1 = model("models/BIOMD0000000021.xml")
model2 = model1.copy()
model2.V_mT = 0.28
model2.V_dT = 4.8
task1 = model1.uniform(0, 380, 1000)
task2 = model2.uniform(0, 380, 1000)
p1 = plot(task1, "time", '[Mt]', "task1 [Mt]")
p1.addPlot(task2, "time", "[Mt]", "task2 [Mt]")
p1.set_ylabel("Concentration")
p2 = plot(task1, "[Cn]", "[Mt]", "task1")
p2.addPlot(task2, "[Cn]", "[Mt]", "task2")
p2.set_ylabel("[Mt]")
