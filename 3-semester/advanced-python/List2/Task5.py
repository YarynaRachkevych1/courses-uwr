def compress(text):
    res = []
    cnt = 1
    for i in range(0, len(text)-1):
        if text[i] == text[i+1]:
                cnt += 1
        else:
            res.append(tuple((cnt, text[i])))
            cnt = 1
    res.append(tuple ((cnt, text[len(text)-1])))
    return res

def decompress(list):
    res =''
    for pair in list:
        res += pair[1]*pair[0]
    return res

print(compress('suuuuper'))
print(decompress([(1, 's'), (4, 'u'), (1, 'p'), (1, 'e'), (1, 'r')]))
print(compress('suuuuperrrr'))
print(decompress([(1, 's'), (4, 'u'), (1, 'p'), (1, 'e'), (4, 'r')]))

text2 = open('TheMetamorphosis.txt', 'r', encoding='UTF-8').read()
#print(compress(text2))

# Źródło tekstu text2:
# https://www.gutenberg.org/cache/epub/5200/pg5200.txt