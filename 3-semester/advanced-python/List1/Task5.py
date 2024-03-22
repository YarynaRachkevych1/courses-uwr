def common_prefix(word_list):
    if len(word_list) < 3:
        return "Lista jest za mała"
    
    word_list_ord = (sorted (list (map(lambda x: x.lower(), word_list))))
    etalon = ''
    for i in range(0, len(word_list_ord) - 2):         
        for j in reversed(range(0, len(word_list_ord[i]))):
            curr_prefix = word_list_ord[i][:j+1] 
            if (curr_prefix in word_list_ord[i]) and (curr_prefix in word_list_ord[i+1]) and (curr_prefix in word_list_ord[i+2]):
                if len(curr_prefix) > len(etalon):
                    etalon = curr_prefix
                
                
    return etalon

print(common_prefix(["Cyprian", "cyberotoman", "cynik", "ceniąc", "czule"]))
print(common_prefix(["moj_prefiks_cos", "moj_prefiks_drugi", "moj_prefiks_niewazne"]))
print(common_prefix(["cy", "da", "Dam", "dem", "daam"]))
print(common_prefix(["y", "yy", "jak", "y", "jk", "jk"]))