import sys

# 재귀깊이해제
sys.setrecursionlimit(100000)

cache = []
n = 0
lock = []
lock_solved = []

def get_lock(dir, pos, target_pos):
    if dir: #왼쪽
        if pos > target_pos:
            return target_pos + 10 - pos
        
        return target_pos - pos
    
    else:      #rughtrught
        if pos < target_pos:
            return pos + 10 - target_pos
        
        return pos - target_pos

def change_circle(num):
    if num < 10:
        return num
    
    return num - 10

def solve(idx, left):
    global n, lock, lock_solved, cache

    if idx == n:
        return 0

    left = left % 10

    if cache[idx][left] != -1:
        return cache[idx][left]

    left_temp = change_circle(lock[idx] + left)

    left_move = get_lock(1, left_temp, lock_solved[idx])     #왼쪽
    right_move = get_lock(0, left_temp, lock_solved[idx])     #왼쪽

    left_ans = solve(idx + 1, left + left_move) + left_move 
    right_ans = solve(idx + 1, left) + right_move 

    cache[idx][left] = min(left_ans, right_ans)

    return cache[idx][left]


if __name__ == "__main__":
    n = int(input())
    lock = list(map(int, input()))
    lock_solved = list(map(int, input()))

    cache = [[-1] * 10 for _ in range(10001)]

    print(solve(0, 0))

