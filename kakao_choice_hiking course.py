import heapq

visited = []

def bfs(node, goal, map_paths):
    global visited
    
    pq = []
    ans = -1
    heapq.heappush(pq, [0, node])
    
    while pq:
        time, node = heapq.heappop(pq)
        
        if visited[0]:
            continue
        else:
            visited[node] = 1
            
        ans = max(ans, time)
        
        if node in goal:
            return ans
        
        for map_node in map_paths[node]:
            if not visited[map_node[1]]:
                heapq.heappush(pq, map_node)
                
    return 0
        
def solution(n, paths, gates, summits):
    global visited
    
    answer = []
    map_paths= [[] * (n + 1) for i in range((n + 1))]
    summits.sort()
    
    for path in paths:
        start = path[0]
        end = path[1]
        time = path[2]
        
        map_paths[start].append([time, end])
        map_paths[end].append([time, start])
    
    answer = [-1, 10000001]
    
    for summit in summits:
        visited = [0] * (n + 1)
        
        for v in summits:
            visited[v] = 1
            
        visited[summit] = 0
        cand_ans = bfs(summit, gates, map_paths)
        
        if cand_ans == 0:
            continue
        
        if cand_ans < answer[1]:
            answer[0] = summit
            answer[1] = cand_ans
    
    return answer