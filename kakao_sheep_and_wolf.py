from collections import defaultdict

nodes = []
edges = []
cache = []

def dfs(node, visited):
    global nodes, edges

    sheep = 0
    wolf = 0

    if cache[node][visited] != -1:
        return cache[node][visited]

    #방문 순서에 따른 wolf, sheep
    for i in range(len(nodes)):
        if visited & (1 << i) != 0:
            if nodes[i] == 0:
                sheep += 1
            else:
                wolf += 1

    cache[node][visited] = 0
    if sheep <= wolf:
        return cache[node][visited] 

    cache[node][visited] = sheep
    childes = []

    for edge in edges:
        if edge[0] == node:
            childes.append(edge[1])
        if edge[1] == node:
            childes.append(edge[0])
    
    for child in childes:
        cache[node][visited]  = max(cache[node][visited] , dfs(child, visited | (1 << child)))

    return cache[node][visited] 

def solution(info, edge):
    global nodes, edges, cache

    nodes = info
    edges = edge
    cache = [[-1] * (1 << 17) for _ in range(17)]

    return dfs(0, 1)



if __name__ == "__main__":
    info = [0,0,1,1,1,0,1,0,1,0,1,1]
    edges = [[0,1],[1,2],[1,4],[0,8],[8,7],[9,10],[9,11],[4,3],[6,5],[4,6],[8,9]]

    print(solution(info, edges))