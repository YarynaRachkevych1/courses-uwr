def pom_kompresja(tekst,lista,litera,licznik):
    # print(str(tekst)+" "+ str(lista)+" " + str(litera)+" " + str(licznik))
    if len(tekst) == 0:
        lista.append((licznik,litera))
        print(lista)
        return lista
    elif tekst[0] == litera:
        return pom_kompresja(tekst[1:],lista,litera,licznik+1)
    else:
        lista.append((licznik, litera))
        return pom_kompresja(tekst[1:],lista,tekst[0],1)

def kompresja(tekst):
    lista = []
    return pom_kompresja(tekst[1:],lista,tekst[0],1)

def dekompresja(tekst_skompresowany):
    tekst = ""
    for krotka in tekst_skompresowany:
        tekst = tekst + krotka[0]*krotka[1]
    return tekst

# print(dekompresja([(1,"a"),(1,"m"),(1,"e"),(1,"l"),(1,"i"),(4,"a")]))
print(kompresja("ewjjjjjjlla")) #nie dziala, nwm o co biega... #wyrzuca None
# print(kompresja(open('lalka-tom-pierwszy.txt').read()))