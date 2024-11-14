import math
def pochodna(f):
    H = 10 ** - 6
    return lambda x: (f(x + H) - f(x)) / H

def newton(f, x0, n = 100):
    xn = x0
    for i in range(n):
        xn = xn - f(xn) / pochodna(f)(xn)
    return xn

def zadanie7(m, c, x0):
    if c % 2 == 0:
        return newton(lambda x: x - 2**(c//2) * math.sqrt(m), x0)
    else:
        return newton(lambda x: x - 2**((c-1)//2) * math.sqrt(2*m), x0)
    
# a = 0.78125 * 2^5  == 25

for i in range(20, 30):
    print(zadanie7(0.78125, 5, i))