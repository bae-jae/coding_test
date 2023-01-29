import heapq
from collections import defaultdict

def check_is_out_range(n_y, m_x, y, x):
    if (1 <= y <= n_y) and (1 <= x <= m_x):
        return False
    return True

def solution(n_y, m_x, x, y, r, c, k):
    y, x = x, y

    my = [-1, 0, 1, 0]
    mx = [0, 1, 0, -1]
    dir = ['u','r', 'd', 'l']
    
    heap = []
    heapq.heappush(heap, ["", y , x])

    while heap:
        state, y, x = heapq.heappop(heap)
        dist = abs(r - y) + abs(c - x)  #최단거리
        remain = k - len(state)

        if (remain - dist) % 2 is 1:
            continue

        if [y, x] == [r, c]:
            if remain is 0:
                return state
        
        if  dist >  remain:
            continue
        
        for d_y, d_x, d in zip(my, mx, dir):
            r_y = y + d_y
            r_x = x + d_x
            r_state = state + d

            if not check_is_out_range(n_y, m_x, r_y, r_x):
                heapq.heappush(heap, [r_state, r_y, r_x])

    return "impossible"

if __name__ == "__main__":
    n, m, x, y, r, c, k = [3, 4, 2 , 3 , 3, 1 ,5]
    print(solution(n, m, x, y, r, c, k))