import numpy as np

f2 = lambda x, R: 1/x - R
def newton(x, R):
    eps = np.finfo(float).eps # 2^-16
    xn = lambda x, R: x*(2-x*R)
    iter = 0
    while abs(x - 1/R) >=  eps:
        x = xn(x, R)
        iter += 1
    return x, iter

print(newton(0.00098, 4))

for R in range(1, 10):
    x_list = [(i/100) for i in range(1, 10)]
    for x in x_list:
        result = newton(x, R)
        print(f"x = {x}, R = {R}, res = {result[0]}. It took {result[1]} iterations")