# -*- coding: utf-8 -*-
"""

Created by libsedmlscript v0.0.1
"""

from sed_roadrunner import model, task, plot

from math import e as exponentiale, pi, acos, acosh, asin, asinh, atan, atanh, ceil, cos, cosh, exp, factorial, floor, log, sin, sinh, tan, tanh, sqrt, log10
from mpmath import acot, acoth, acsc, asec, asech, cot, coth, csc, csch, sec, sech

avogadro = 6.02214179e+23

def piecewise(*args):
    halfargs = round(len(args)/2 - 0.25)
    for x in range(halfargs):
        if args[x*2+1]:
            return args[x*2]
    if len(args)>halfargs*2:
        return args[-1]
    return None


def root(n, a):
  return a**(1.0/n)

#----------------------------------------------

abs(0.5)
acos(0.5)
acosh(1.5)
acot(0.5)
acoth(0.5)
acsc(0.5)
asec(0.5)
asech(0.5)
asin(0.5)
asinh(0.5)
atan(0.5)
atanh(0.5)
ceil(0.5)
cos(0.5)
cosh(0.5)
cot(0.5)
coth(0.5)
csc(0.5)
csch(0.5)
exp(0.5)
factorial(5)
floor(0.5)
log(0.5)
log(10, 3)
log10(0.5)
x**3
root(3, 27)
root(2, 25)
sqrt(16)
sec(0.5)
sech(0.5)
sin(0.5)
sinh(0.5)
tan(0.5)
tanh(0.5)
exponentiale
False
pi
True
avogadro
x = 2
y = piecewise(x, x == 3, 5)
