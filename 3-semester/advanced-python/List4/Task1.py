import timeit

def pierwsze_imperatywna(n):
    if n < 2:
        return []
    
    pierwsze = []
    for i in range(2, n):
        flaga = True
        for j in range(2, i//2 + 1):
            if i % j == 0:
                flaga = False
                break
        if flaga:
            pierwsze.append(i)
    return pierwsze

def pierwsze_skladana(n):
    return [i for i in range(2, n) if all (i % j != 0 for j in range(2, i//2+1))]

def pierwsze_funkcyjna(n):
    return list(filter(
        lambda x: all(x % i != 0 for i in range(2, x//2 + 1)), 
        [i for i in range(2, n)]
    ))

print("n   skladana  imperatywna")
for i in range(10, 100, 10):
    time_skladana = timeit.timeit(lambda: pierwsze_skladana(i), number=10000)
    time_imperatywna = timeit.timeit(lambda: pierwsze_imperatywna(i), number=10000)
    print("{0}:    {1:.3f}        {2:.3f}".format(i, time_skladana, time_imperatywna))
