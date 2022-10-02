def solution(id_list, report, k):
    answer = [0] * len(id_list)
    reports = {x : 0 for x in id_list}      
    
    #set으로 중복 제거 후 신고 당한 사람 카운트
    for line in set(report):
        reports[line.split()[1]] += 1
    
    #set으로 중복 제거 후 신고 당한 사람이 k이상이면 신고한 사람의 id.index로 메일 넣어주기 
    for line in set(report):
        if reports[line.split()[1]] >= k:
            answer[id_list.index(line.split()[0])] += 1
                
    return answer