import matplotlib.pyplot as plt
import math

def frange(fr, to, st):
    while fr < to:
        yield fr
        fr += st

def polynomial(points):
    return lambda x: math.prod([x - point for point in points])

def eq_points(n):
    return [x for x in frange(-1, 1, 2/n)]

def c_points(n):
    return [math.cos((2*k + 1) / (2*n + 2) * math.pi) for k in range(0, n+1)]

ps1 = [polynomial(eq_points(n)) for n in range(4, 21)] # rownoodlegle
ps2 = [polynomial(c_points(n)) for n in range(4, 21)]  # wezly Czebyszewa

N = 20 # wybór N

xs = eq_points(100)
ys1 = [ps1[N-4](x) for x in xs]

ys2 = [ps2[N-4](x) for x in xs]

plt.plot(xs, ys1)
plt.plot(xs, ys2)
plt.show()