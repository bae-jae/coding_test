import bisect
from copy import deepcopy
from itertools import combinations


def make_sub_query(info):
    keys = []
    keys.append(" ".join(info))
    for k in range(1, 5):
        for sub in list(combinations(range(0, 4), k)):
            case = deepcopy(info)

            for idx in sub:
                case[idx] = '-'

            keys.append(" ".join(case))
    return keys


def solution(infos, querys):

    info_dict = {}
    
    for info in infos:
        lang, ground, pos, food, score = info.split()
        query_set = make_sub_query([lang, ground, pos, food])

        for q in query_set:
            if q in info_dict.keys():
                info_dict[q].append(int(score))
            else:
                info_dict[q] = [int(score)]

    for key in info_dict.keys():
        info_dict[key].sort()

    answer = []

    for q in querys:
        q = q.replace(" and", "")
        lang, ground, pos, food, score = q.split()

        query_of_key = " ".join([lang, ground, pos, food])

        if query_of_key in info_dict.keys():
            score_list = info_dict[query_of_key]
            answer.append(len(score_list) - bisect.bisect_left(score_list, int(score)))

        else:
            print("Asd")
            answer.append(0)

    return answer
    

if __name__ == "__main__":
    info = ["java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"]
    query = ["java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"]
    print(solution(info, query))