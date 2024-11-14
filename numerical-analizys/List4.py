def zadanie3(a, b):
    kroki = 5
    for i in range(kroki):
        srodek = (a + b)/2
        if f(srodek) > 0:
            b = srodek
        elif f(srodek) < 0:
            a = srodek
        else:
            return srodek
    return srodek
        
def f(x):
    return x - 0.49

print(zadanie3(0, 1))