def qualified(votes):
    qualified_list = filter(lambda x: True if x/sum(votes) > 0.05 else False, votes)
    return list(qualified_list)


def pretty_print(stats):
    pretty_res = ''
    j = 1
    for i in range(0, len(stats), 2):
        pretty_res += "Partija Nr: {}, ".format(j) + "Miejsca do obsadzenia: {}".format(stats[i+1]) + '\n'
        j += 1
    return pretty_res

def count_seats(vote_list, n):
    vote_list = qualified(vote_list)
    org_votes = vote_list.copy()
    res = []
    for i in range(0, n):
        max_votes = max(vote_list)
        max_votes_index = vote_list.index(max_votes)
        if str(max_votes_index) in res:
            index_to_add = res.index(str(max_votes_index))
            res[index_to_add+1] += 1
        else: 
            res.append(str(max_votes_index))
            res.append(1)
        S = res[res.index(str(max_votes_index)) + 1]
        vote_list[max_votes_index] = org_votes[max_votes_index] // (S + 1)
    return pretty_print(res)

votes1 = [100000, 80000, 30000, 20000, 10]
votes2 = [50000, 42000, 19000]
print(count_seats(votes1, 8))
print(count_seats(votes2, 10))