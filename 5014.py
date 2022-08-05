


from cmath import cos
from collections import deque


if __name__ == "__main__":
    f,s,g,u,d = map(int, input().split())

    calc_cache = {}
    calc_cache[s] = 0
    queue = deque()
    queue.append((0, s))

    #제일 간단한 brute force

    ans = -1
    while queue:
        cost, value =  queue.popleft()

        if value == g:
            ans = cost
            break

        if value + u <= f:
            if not value + u in calc_cache:
                calc_cache[value + u] = cost + 1
                queue.append((cost + 1, value + u))
        
        if 1 <= value - d:
            if not value - d in calc_cache:
                calc_cache[value - d] = cost + 1
                queue.append((cost + 1, value - d))

    print(ans if ans != -1 else "use the stairs")

