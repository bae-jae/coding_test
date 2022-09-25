from itertools import combinations_with_replacement as cwr
from collections import Counter

def get_score(info, score_tabel):

    jaeji = 0
    jondan = 0

    for i in range(len(info)):
        if info[i] == 0 and score_tabel[i] == 0:
            continue

        if info[i] < score_tabel[i]:
            jondan += i
        
        else:
            jaeji += i
    
    return jondan - jaeji

            

def solution(n, info) :
    answer = [0] * len(info)
    info = info[::-1]
    k = len(info)
    max_diff = 0

    for score_tabel in cwr(range(0, k), n) :
        ryan = 0
        apeach = 0
        
        score_tabel = Counter(score_tabel)
        score_diff = get_score(info, score_tabel)

        if max_diff < score_diff:
            max_diff = score_diff
            
            for i in range(k):
                answer[i] = score_tabel[i]

        

    answer = answer[::-1]
    print(answer)
    return answer

if __name__ == "__main__":
    n = 3
    info = [0,0,1,0,0,0,0,0,0,1,0]

    solution(n, info)

