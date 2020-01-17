# -*- coding: utf-8 -*-
"""

Created by libsedmlscript v0.0.1
"""

from sed_roadrunner import model, task, plot


def piecewise(*args):
    halfargs = round(len(args)/2 - 0.25)
    for x in range(halfargs):
        if args[x*2+1]:
            return args[x*2]
    if len(args)>halfargs*2:
        return args[-1]
    return None

#----------------------------------------------

x = 2
y = piecewise(x, x == 3, 5)
