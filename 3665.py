import sys
from collections import deque

c = int(sys.stdin.readline())
for __ in range(c):
    n = int(sys.stdin.readline())
    ranking = list(map(int, sys.stdin.readline().split()))

    q = deque()
    tree = [[] for _ in range(n + 1)]
    in_degree = [0] * (n + 1)

    for i in range(0, n - 1):
        for j in range(i + 1, n):
            tree[ranking[i]].append(ranking[j])
            in_degree[ranking[j]] += 1

    m = int(sys.stdin.readline())
    for _ in range(m):
        a, b = map(int, sys.stdin.readline().split())
        check = True
        for i in tree[a]:
            if i == b:
                tree[a].remove(b)
                tree[b].append(a)
                in_degree[b] -= 1
                in_degree[a] += 1
                check = False
        if check:
            tree[b].remove(a)
            tree[a].append(b)
            in_degree[a] -= 1
            in_degree[b] += 1

    for i in range(1, n + 1):
        if in_degree[i] == 0:
            q.append(i)

    result = True
    result_list = []
    if not q:
        result = False
    while q:
        if len(q) > 1:
            result = False
            break
        now = q.popleft()
        result_list.append(now)
        for i in tree[now]:
            in_degree[i] -= 1
            if in_degree[i] == 0:
                q.append(i)
            elif in_degree[i] < 0:
                result = False
                break

    if not result or len(result_list) < n:
        print('IMPOSSIBLE')
    else:
        print(*result_list)