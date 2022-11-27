from collections import Counter
from collections import defaultdict

import itertools

def solution(orders, course):
    answer = []
    cand_comb_menu = []

    for num in course:
        for order in orders:
            comb_menues = list(itertools.combinations(order, num))

            #AC, AD, AE
            for comb_menu in comb_menues:
                comb_menu = sorted(comb_menu)
                cand_comb_menu.append("".join(comb_menu))

    cand_comb_menu = Counter(cand_comb_menu).most_common()

    best_like_dict = defaultdict(int)

    for course_num in course:
        best_like = 0

        for menu, like in cand_comb_menu:
            if len(menu) == course_num:
                best_like = max(best_like, like)

        best_like_dict[course_num] = best_like

    
    for course_num in course:
        if best_like_dict[course_num] == 0 or best_like_dict[course_num] < 2:
            continue

        for menu, like in cand_comb_menu:
            if len(menu) == course_num and like == best_like_dict[course_num]:
                answer.append(menu)

    print(sorted(answer))
    return answer


if __name__ == "__main__":
    orders = ["ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD"]
    course = [2,3,5]

    solution(orders, course)
    



    