import math
def bisekcja(a, b):
    E = 10 ** (-8)
    m = (a + b)/2
    i = 0
    while abs(f(m)) > E:
        i += 1
        if f(m) * f(b)> 0:
            b = m
        elif f(m) * f(b)< 0:
            a = m
        else:
            return m
        m = (a + b)/2
    print(i)
    return m

def f(x):
    return x**4 - math.log(x+4)

print(bisekcja(-2, -1))
print(bisekcja(1, 2))