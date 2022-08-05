from collections import deque


dir_x = [-1, 0, 1, 0]
dir_y = [ 0, 1, 0, -1]

human_time_map = []
fire_time_map = []

r = 0
c = 0

def out_range(x, y):
    global r, c
    if x < 0 or x >= r or y < 0 or y >= c:
        return 0

    return 1   

def bfs(fire_map, human_point, fire_point):

    global r, c, human_time_map, fire_time_map

    while fire_point:
        x, y = fire_point.popleft()
        next_cost = fire_time_map[x][y] + 1

        for i in range(4):
            next_x = dir_x[i] + x
            next_y = dir_y[i] + y

            if out_range(next_x, next_y) and fire_map[next_x][next_y] != '#':
                if next_cost < fire_time_map[next_x][next_y]:
                    fire_time_map[next_x][next_y] = next_cost
                    fire_point.append((next_x, next_y))

    while human_point:
        x, y = human_point.popleft()
        next_cost = human_time_map[x][y] + 1

        if (x == 0) or (x == r - 1) or (y == 0) or (y == c - 1):
            return next_cost

        for i in range(4):
            next_x = dir_x[i] + x
            next_y = dir_y[i] + y

            if out_range(next_x, next_y) and fire_map[next_x][next_y] != '#' and next_cost < fire_time_map[next_x][next_y]:
                if next_cost < human_time_map[next_x][next_y]:
                    human_time_map[next_x][next_y] = next_cost
                    human_point.append((next_x, next_y))

    return "IMPOSSIBLE"

if __name__ == "__main__":
    n = int(input())

    for _ in range(n):
        c, r = map(int, input().split())

        first_map = [] * r

        human_time_map = [[987654321] * c for _ in range(r)]
        fire_time_map = [[987654321] * c for _ in range(r)]

        human_point = deque()
        fire_point = deque()

        for _ in range(r):
            first_map.append(input())

        for x in range(r):
            for y in range(c):
                if first_map[x][y] == '@':
                    human_time_map[x][y] = 0
                    human_point.append((x,y))
                elif first_map[x][y] == '*':
                    fire_time_map[x][y] = 0
                    fire_point.append((x,y))

        print(bfs(first_map, human_point, fire_point))

