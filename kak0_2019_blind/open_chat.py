from collections import defaultdict
from turtle import position

def solution(record):
    answer = []
    
    book = defaultdict(str)

    for i in record:
        info = i.split()

        if info[0] == "Leave":
            continue

        book[info[1]] = info[2]
    
    print(book)
    for i in record:
        info = i.split()

        if info[0] == "Change":
            continue

        uid = info[1]
        name = book[uid]

        if info[0] == "Enter":
            answer.append(name+"님이 들어왔습니다.")
        elif info[0] == "Leave":
            answer.append(name+"님이 나갔습니다.")

    return answer



if __name__ == "__main__":
    record = ["Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"]
    result = ["Prodo님이 들어왔습니다.", "Ryan님이 들어왔습니다.", "Prodo님이 나갔습니다.", "Prodo님이 들어왔습니다."]

    print(solution(record))