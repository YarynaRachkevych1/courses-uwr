import matplotlib.pyplot as plt

xs = [-9, -6, 0, 6, 9]
ys = [-3, 4, -2, 4, -3]

def fun(x):
    return (-55/1323) * (x**2 - 234/5)

xs_f = [i for i in range(0, 50)]
ys_f = [fun(i) for i in range(0, 50)]

fig, axs1 = plt.subplots(figsize=(7, 7.5))

plt.scatter(xs, ys)
plt.plot(xs_f, ys_f)
plt.show()