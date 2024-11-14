import numpy as np

def create_ponits(xs, ys):
    n = len(xs)
    res = []
    for i in range(n):
        res.append((xs[i], ys[i]))
    return res

def de_casteljau(points, t):
    if len(points) == 1:
        return points[0]
    else:
        new_points = [((1 - t) * points[i][0] + t * points[i + 1][0],
                       (1 - t) * points[i][1] + t * points[i + 1][1])
                      for i in range(len(points) - 1)]
        return de_casteljau(new_points, t)

def bezier_curve(control_points, num_points=100):
    t_values = np.linspace(0, 1, num_points)
    curve_points = [de_casteljau(control_points, t) for t in t_values]
    return zip(*curve_points)