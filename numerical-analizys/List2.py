import math

def f9(k):
    k1 = k - 1
    prev_x = 2
    res = 2
    if k == 1:
        return prev_x
    for i in range(2, k):
        res = 2**k1 * math.sqrt(2*
                            (1 - math.sqrt(1 - (prev_x/2**k1)**2)))
        prev_x = res
    return res

def better_f9_2(k):
    prev_x = 2
    res = 2
    if k == 1:
        return prev_x
    for i in range(2, k):
        res = prev_x * math.sqrt(2 / (1 + math.sqrt(1 - (prev_x / (2**k))**2)))
        prev_x = res
    return res

def better_f9(k):
    if k == 1:
        return 2
    prev_x = better_f9(k - 1)
    return prev_x * math.sqrt(2 / (1 + math.sqrt(1 - (prev_x / 2**(k - 1))**2)))

for i in range(1, 40):
    print(better_f9_2(i))

print("----------------------")

for i in range(1, 40):
    print(better_f9(i))


def f7(x):
    return 4038 * (1 / x**7 * math.sqrt(1 + 1/x**14) + 1)

#print(f'{f7(0.001):.3f}')

def f8(x):
    return 28 * (math.sin(17/2 * x) ** 2) / x **2

# for i in range(11, 20):
#     print(f8(10**(-i)))
    