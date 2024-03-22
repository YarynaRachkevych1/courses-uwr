import math

def f2(x):
    return 4046 * (math.sqrt((x**14) + 1) - 1) / x ** 14

#print(f'{f1(0.001):.3f}')

def f3(x):
    return 14 * (1 - math.cos(17*x)) / x**2

#print("To f3: ", (f3(10**(-11))))

def f4(n):
    if n == 0:
        return 1
    if n == 1: 
        return -1/9
    n0 = 1
    n1 = -1/9
    for i in range(2, n+1):
        n_rez = 80/9 * n1 + n0
        n0 = n1
        n1 = n_rez
    return n_rez

# for i in range(0, 50):
#     print(f4(i))

def f5(n):
    I0 = math.log(2024/2023)
    if n == 0:
        return I0
    for i in range(1, n+1):
        In = (1/i) - 2023*I0
        I0 = In
        
    return In

# for i in range(1, 19, 2):
#     print(f5(i))

# print("-----------------------")

# for i in range(2, 20, 2):
#     print(f5(i))

def f6():
    pi = 0
    actual_element = 1
    k = 0
    while abs(actual_element) > 0.000001:
        actual_element = 4 * (1 if k % 2 == 0 else -1) / (2 * k + 1)
        pi += actual_element
        k += 1
    print("pi:", pi)
    print("k:", k)

f6()