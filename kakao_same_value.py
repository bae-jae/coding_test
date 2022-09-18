from collections import deque

def solution(queue1, queue2):
    answer = -2
    
    
    sum_of_q1 = sum(queue1)
    sum_of_q2 = sum(queue2)
    
    if (sum_of_q1 + sum_of_q2) % 2:
        return -1
    
    deq_q1 = deque(queue1)
    deq_q2 = deque(queue2)
    
    mid_num = int((sum_of_q1 + sum_of_q2) / 2)
    
    answer = 0
    while sum_of_q1 != mid_num:
            
        if sum_of_q1 == 0 or sum_of_q2 == 0:
            answer = -1
            break
            
        if sum_of_q1 < sum_of_q2:
            poped = deq_q2.popleft()
            deq_q1.append(poped)
            
            sum_of_q1 += poped
            sum_of_q2 -= poped
        else:
            poped = deq_q1.popleft()
            deq_q2.append(poped)
            
            sum_of_q1 -= poped
            sum_of_q2 += poped
        answer += 1
    return answer