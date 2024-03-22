import math

def a(x):
    return 1 / (x**3 + math.sqrt(x**6 + 2023**2))

def lepsze_a(x):
    return math.sqrt(x**6/2023**2 + 1) / 2023**2 - x**3/2023**2

print("Pierwsza wersja a) dla x = 100 000: ", a(100000))
print("Polepszona wersja dla x = 100 000: ", lepsze_a(100000), '\n')

def b(x):
    return math.log2(x) - 2

def lepsze_b(x):
    return math.log2(x/4)

print("Pierwsza wersja b) dla x = 4.000000000000123: ", b(4.000000000000123))
print("Polepszona wersja dla x = 4.000000000000123: ", lepsze_b(4.000000000000123), '\n')

def ctg(x):
    return math.pi/2 - math.atan(x)

def c(x):
    return (math.pi/2 - x - ctg(x)) / x**3

# def lepsze_c(x):
#     return math.atan(x) / x**3 - 1 / x**2

def lepsze_c(x):
    dokladnosc = 100
    wynik = 0 
    for i in range(2, dokladnosc):
        wynik += (-1)**i * 2**(2*i + 1) / (2*i + 1)
    return (math.pi - wynik) / x**3

print("Pierwsza wersja c) dla x = 0.00000000123: ", c(0.00000000123))
print("Polepszona wersja dla x = 0.00000000123: ", lepsze_c(0.00000000123), '\n')

# Zadanie 2

from math import sqrt

def get_roots(a, b, c):
    x1 = (-b + sqrt(b ** 2 - 4 * a * c)) / (2 * a)
    x2 = (-b - sqrt(b ** 2 - 4 * a * c)) / (2 * a)
    return x1, x2

def better_get_roots(a, b, c):
    if b > 0:
        x1 = (-b - sqrt(b ** 2 - 4 * a * c)) / (2 * a)
    else:
        x1 = (-b + sqrt(b ** 2 - 4 * a * c)) / (2 * a)

    return x1, c / a / x1

print(get_roots(1, 10 ** 31, 1))
print(get_roots(1, -10 ** 31, 1))

print(better_get_roots(1, 10 ** 31, 1))
print(better_get_roots(1, -10 ** 31, 1))