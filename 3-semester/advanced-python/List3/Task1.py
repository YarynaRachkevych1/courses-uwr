from collections import deque 

def search_around_i(text, left, right):
    while left >= 0 and right < len(text) and text[left] == text[right]:
        left -= 1
        right += 1
    return left + 1, right - left - 1

def correct_append(palindromes_list, start, length):
    if length> 2:
        if len(palindromes_list) != 0:
            f_pair = palindromes_list[0]
            if length > f_pair[1]:
                palindromes_list = []
                palindromes_list.append((start, length))
            elif length == f_pair[1]:
                palindromes_list.append((start, length))
        else:
            palindromes_list.append((start, length))
    return palindromes_list

def find_palindromes(text):
    text = text.lower()
    palindromes = deque([])

    for i in range(0, len(text)):
        start1, length1 = search_around_i(text, i, i)
        start2, length2 = search_around_i(text, i, i + 1)
        palindromes = correct_append(palindromes, start1, length1)
        palindromes = correct_append(palindromes, start2, length2)

    return palindromes

text1 = "Anna is driving her Civic racecar , that blue racecar is hers."
text2 = " Kajak to fascynujący pojazd wodny, który cieszy się ogromną popularnością wśród miłośników \
    aktywnego wypoczynku. Kajak to doskonały wybór zarówno dla początkujących, \
    jak i doświadczonych entuzjastów sportów wodnych. \
    Kajak to nie tylko fantastyczny środek transportu po wodzie, ale również sposób na bliski kontakt z naturą."
print(list(find_palindromes(text1)))
print(list(find_palindromes(text2)))