import heapq

def get_maximum_cost(problems):
    max_alp = -1
    max_cop = -1
    
    for problem in problems:
        alp_req, cop_req, _, _, _ = problem
        
        max_alp = max(max_alp, alp_req)
        max_cop = max(max_cop, cop_req)
        
    return max_alp, max_cop

def change_value(v):
    return min(150, v)

def get_out_range(x, y):
    if x >= 151 or y >= 151:
        return 1
    
    return 

def bfs(alp_init, cop_init, problems):
    ans = -1
    
    max_alp, max_cop = get_maximum_cost(problems)
    
    pq = []
    heapq.heappush(pq, [0, alp_init, cop_init])
    
    max_len = 151
    cache = [[987654321] * max_len for _ in range(max_len)]
    cache[alp_init][cop_init] = 0
    
    while pq:
        time, alp, cop = heapq.heappop(pq)
        
        if max_alp <= alp and max_cop <= cop:
            return time
        
        if cache[alp][cop] < time:
            continue
        
        alp = change_value(alp)
        cop = change_value(cop)
        
        if alp + 1 < max_len and time + 1 < cache[alp + 1][cop]:
            cache[alp + 1][cop] = time + 1
            heapq.heappush(pq, [time + 1, alp + 1, cop])
            
        if cop + 1 < max_len and time + 1 < cache[alp][cop + 1]:
            cache[alp][cop + 1] = time + 1
            heapq.heappush(pq, [time + 1, alp, cop + 1])
    
        for idx in range(len(problems)):
            algo, codeing, algo_rwd, codeing_rwd, need_time = problems[idx]
            
            if algo <= alp and codeing <= cop:
                cost = time + need_time
                
                total_alp = alp + algo_rwd
                total_cop = cop + codeing_rwd
                
                
                total_alp = change_value(total_alp)
                total_cop = change_value(total_cop)

                if cost < cache[total_alp][total_cop]:
                    cache[total_alp][total_cop] = cost
                    heapq.heappush(pq, [cost, total_alp, total_cop])
                    
    return -1

def solution(alp, cop, problems):
    answer = 0
    
    answer = bfs(alp, cop, problems)
    return answer