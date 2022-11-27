

from collections import defaultdict, deque
from copy import deepcopy
from itertools import permutations


def check_out_range(x ,y):
    if 0 <= x < 4 and 0 <= y < 4:
        return 0
    
    return 1

def bfs(board, sx, sy, rx , ry):

    visited =[[987654321] * 4 for _ in range(4)]

    queue = deque()
    queue.append([sx, sy, 0])

    visited[sx][sy] = 0

    while queue:
        ox, oy, cost = queue.pop()

        if ox == rx and oy == ry:
            return cost

        for dx, dy in [(-1, 0), (0, 1), (1, 0), (0, -1)]:
            mx = ox + dx
            my = oy + dy

            if not check_out_range(mx, my):
                if cost + 1 < visited[mx][my]:
                    visited[mx][my] = cost + 1
                    queue.append([mx, my, cost + 1])
            else:
                continue

            while not check_out_range(mx + dx, my + dy) and board[mx + dx][my + dy] == 0:
                mx = mx + dx
                my = my + dy

            if cost + 1 < visited[mx][my]:
                visited[mx][my] = cost + 1
                queue.append([mx, my, cost + 1])

def get_card_point(board, point):
    for i in range(4):
        for j in range(4):
            if board[i][j] == point:
                return i, j


def dfs(board, sx, sy, rx, ry):
    temp_board = deepcopy(board)

    answer = 0
    
    answer += bfs(temp_board, sx, sy, rx, ry) #도착 한 곳
    point = temp_board[rx][ry]
    temp_board[rx][ry] = 0

    rrx, rry = get_card_point(temp_board, point)
    answer += bfs(temp_board, rx, ry, rrx, rry)
    temp_board[rrx][rry] = 0

    answer += 2

    for i in range(4):
        for j in range(4):
            if temp_board[i][j] != 0:
                answer = min(answer, dfs(temp_board, rrx, rry, i, j))

    return answer

def solution(board, r, c):
    answer = 987654321

    for i in range(4):
        for j in range(4):
            if board[i][j] != 0:
                answer = min(answer, dfs(board, r, c, i, j))

    return answer


if __name__ == "__main__":
    board = [[1,0,0,3],[2,0,0,0],[0,0,0,2],[3,0,1,0]]
    r = 1
    c = 0
    

    print(solution(board, r , c))