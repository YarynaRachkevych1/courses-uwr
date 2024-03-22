import random

def simplify(text, len_w, count_w):
    res = []
    words_list = text.split()
    for word in words_list:
        if len(word) < len_w:
            res.append(word)
    while len(res) > count_w:
        i = random.randint(0, len(res) - 1)
        res.pop(i)
    return res

text = "Podział peryklinalny inicjałów wrzecionowatych \
kambium charakteryzuje się ścianą podziałową inicjowaną \
w płaszczyźnie maksymalnej."

text2 = open('TheMetamorphosis.txt', 'r', encoding='UTF-8').read()

print(simplify(text, 10, 5))
print(simplify(text2, 10, 77))

# Źródło tekstu text2:
# https://www.gutenberg.org/cache/epub/5200/pg5200.txt