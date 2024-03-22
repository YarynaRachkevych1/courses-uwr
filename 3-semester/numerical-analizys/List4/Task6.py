import numpy as np
import math

def newton(x0, a):
    eps = np.finfo(float).eps # 2^-16
    xn = x0
    iter = 0
    while abs(xn - 1/math.sqrt(a)) >= eps:
        xn = 0.5 * x0 * (3 - a * x0 * x0)
        x0 = xn
        iter += 1
    return xn, iter

print(newton(1/10, 4))

for a in range(1, 10):
    x_list = [(i/10) for i in range(1, 10)]
    for x in x_list:
        result = newton(x, a)
        print(f"x = {x}, a = {a}, res = {result}.")
    print()