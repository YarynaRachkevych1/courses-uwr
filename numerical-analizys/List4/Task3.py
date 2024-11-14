def bisekcja(a, b):
    kroki = 6
    a0, b0 = a, b
    for i in range(1, kroki):
        m = (a + b)/2
        if f(m) > 0:
            b = m
        elif f(m) < 0:
            a = m
        else:
            return m
        blad = 2 **(-i-1) * (b0 - a0)
        oszacw_bledu = abs(0.49 - m)
        print(f"X w kroku {i}: {m}")
        print("En: {}, oszacowanie bledu: {:.4f}".format(blad, oszacw_bledu))
        print(f"Ich roznica: {abs(oszacw_bledu - blad)} \n")
    return m
        
def f(x):
    return x - 0.49

bisekcja(0, 1)