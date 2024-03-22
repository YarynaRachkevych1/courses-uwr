def clear(text):
    new = ''
    NotAllowed = ['.', ',', '!', '?', ':', ';', '(', ')', ' ']
    for char in text:
        if char not in NotAllowed:
            new += char
    return new

def is_palindrom(text):
    new_text = clear(text.lower())
    new_text_rev = new_text[::-1]
    return new_text == new_text_rev

print(is_palindrom("Míč omočím."))
print(is_palindrom("Eine güldne, gute Tugend: Lüge nie!"))