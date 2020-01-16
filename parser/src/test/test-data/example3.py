# -*- coding: utf-8 -*-
"""

Created by libsedmlscript v0.0.1
"""

from sed_roadrunner import model, task, plot

#----------------------------------------------

model1 = model("models/BorisEJB.xml")
model1.outputVariables = ["time", "MAPK", "MAPK_P", "MAPK_PP", "MKK_P", "MKKK", "MKKK_P"]
p1 = plot()
for x in range(10):
   mod = model1.copy()
   onesim = mod.uniform(0, 4000, stochastic = True, seed = 1003 * (x + 1))
   output = {}
   for element in onesim:
      out = element
      if out != "time":
         out = element + "_" + str(x + 1)
      output[out] = onesim[element]
   p1.addPlot(output, "time")
p1.show()
