def make_stats(text):
    words_list = text.split()
    letter_list = [l.lower() for word in words_list for l in word if l.isalpha()]
    letter_list.sort()
    letter_stats = []
    cnt = 1
    length = len(letter_list)
    for i in range(0, length-1):
        if letter_list[i] != letter_list[i+1]:
            letter_stats.append(tuple((cnt/length, letter_list[i])))
            cnt = 0
        else: cnt+=1
    return letter_stats

text1 = "With the recap of the Python lists fresh in mind you !can easily see, that defining and creating lists in Python can be a tiresome job"

print(make_stats(text1))