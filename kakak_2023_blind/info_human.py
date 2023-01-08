def y_to_day(year):
    return year * 336

def m_to_day(month):
    return month * 28

def get_day(today):
    year, month, day = map(int, today.split("."))
    return y_to_day(year) + m_to_day(month) + day

def solution(today, terms, privacies):
    answer = []
    doc = {}

    today = get_day(today)
    
    for i in terms:
        type_doc, mon_dur = i.split()
        doc[type_doc] = int(mon_dur)

    for i in range(len(privacies)):
        day, type_doc = privacies[i].split()
        duration = doc[type_doc]

        expire_time = get_day(day) + m_to_day(duration)
        
        if expire_time <= today:
            answer.append(i + 1)

    return answer


if __name__ == "__main__":
    today = "2022.05.19"
    terms = ["A 6", "B 12", "C 3"]
    privacies = ["2021.05.02 A", "2021.07.01 B", "2022.02.19 C", "2022.02.20 C"]

    print(solution(today, terms, privacies))