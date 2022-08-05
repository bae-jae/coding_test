
from collections import deque
from numpy import append


rgb_map = []
normal_grid = []
annormal_grid = []

dir_x = [-1, 0, 1, 0]
dir_y = [ 0, 1, 0, -1]
n = 0

def out_range(x, y):
    global n

    if x < 0 or x >= n or y < 0 or y >= n:
        return 0

    return 1   

def bfs_normal(startx, starty, area):
    global normal_grid

    cell_color = rgb_map[startx][starty]

    points = deque()
    points.append((startx, starty))
    
    while points:
        x, y = points.popleft()
        normal_grid[x][y] = area

        for i in range(4):
            next_x = dir_x[i] + x
            next_y = dir_y[i] + y

            if out_range(next_x, next_y) and rgb_map[next_x][next_y] == cell_color and normal_grid[next_x][next_y] == -1:
                normal_grid[next_x][next_y] = area
                points.append((next_x, next_y))

def bfs_annormal(startx, starty, area):
    global annormal_grid
    
    cell_color = rgb_map[startx][starty]

    points = deque()
    points.append((startx, starty))
    
    while points:
        x, y = points.popleft()
        annormal_grid[x][y] = area

        for i in range(4):
            next_x = dir_x[i] + x
            next_y = dir_y[i] + y

            if out_range(next_x, next_y) and annormal_grid[next_x][next_y] == -1:
                if (cell_color == "R" or cell_color == 'G') and rgb_map[next_x][next_y] != 'B':
                    annormal_grid[next_x][next_y] = area
                    points.append((next_x, next_y))
                elif cell_color == "B" and rgb_map[next_x][next_y] == 'B':
                    annormal_grid[next_x][next_y] = area
                    points.append((next_x, next_y))






if __name__ == "__main__":

    n = int(input())

    normal_grid = [[-1] * n for _ in range(n)]
    annormal_grid = [[-1] * n for _ in range(n)]

    for i in range(n):
        rgb_map.append(input())

    
    normal_grid_count = 0

    for i in range(n):
        for j in range(n):
            if normal_grid[i][j] == -1:
                bfs_normal(i, j, normal_grid_count)
                normal_grid_count += 1

    annormal_grid_count = 0
    for i in range(n):
        for j in range(n):
            if annormal_grid[i][j] == -1:
                bfs_annormal(i, j, annormal_grid_count)
                annormal_grid_count += 1

    print(normal_grid_count, annormal_grid_count)