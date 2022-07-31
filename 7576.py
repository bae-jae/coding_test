import heapq


dir_x = [-1, 0, 1, 0]
dir_y = [ 0, 1, 0, -1]
n = 0
m = 0

def check_boundary(x, y):
    global n, m

    if x < 0 or x >= m:
        return 0
    
    if y < 0 or y >= n:
        return 0

    return 1

def expand_cost(tomato, target_x, target_y, cost_heap):

    next_cost = tomato[target_x][target_y] + 1

    for i in range(4):
        next_x = dir_x[i] + target_x
        next_y = dir_y[i] + target_y

        if check_boundary(next_x, next_y):
                if tomato[next_x][next_y] != -1 and next_cost < tomato[next_x][next_y]:
                    heapq.heappush(cost_heap, (next_cost, next_x, next_y))
                    tomato[next_x][next_y] = next_cost

            

def simul(cost_heap, tomato):

    while cost_heap:
        cost, x ,y, = heapq.heappop(cost_heap)

        if cost <= tomato[x][y]:
            tomato[x][y] = cost
            expand_cost(tomato, x, y, cost_heap)

if __name__ == "__main__":
    n, m = map(int, input().split())
    tomato = []

    for _ in range(m):
        tomato.append(list(map(int, input().split())))

    cost_heap = []
    for x in range(m):
        for y in range(n):
            if tomato[x][y] == 1:
                heapq.heappush(cost_heap, (0, x ,y))
            elif tomato[x][y] == 0:
                tomato[x][y] = 987654321


    simul(cost_heap,tomato)
    ans = 0

    for x in range(m):
        for y in range(n):
            ans = max(ans, tomato[x][y])

    if ans == 987654321:
        print(-1)
    else:
        print(ans)

