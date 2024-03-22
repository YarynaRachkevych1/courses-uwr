def verbal_to_numerical(number):
    number_dict = {
        'zero': 0, 'one': 1, 'two': 2, 'three': 3, 'four': 4, 'five': 5, 'six': 6, 'seven': 7, 'eight': 8, 'nine': 9,
        'ten': 10, 'eleven': 11, 'twelve': 12, 'thirteen': 13, 'fourteen': 14, 'fifteen': 15, 'sixteen': 16, 'seventeen': 17, 'eighteen': 18, 'nineteen': 19,
        'twenty': 20, 'thirty': 30, 'forty': 40, 'fifty': 50, 'sixty': 60, 'seventy': 70, 'eighty': 80, 'ninety': 90,
        'hundred': 100, 'thousand': 1000
    }

    number = number.replace('-', ' ')
    numbers = number.split()
    res = 0

    for n in numbers:
        if n == 'hundred':
            res *= 100
        elif n == 'thousand':
            res *= 1000
        else:
            res += number_dict[n]

    return res

def sort_numbers(numbers):
    return list(sorted(numbers,key=verbal_to_numerical, reverse=True))

numbers1 = [
    'five hundred',
    'one thousand five hundred',
    'sixty-nine',
    'two hundred seventy-five',
    'seventy-two thousand five hundred',
    'ninety-nine thousand nine hundred ninety-nine',]
print(sort_numbers(numbers1))
