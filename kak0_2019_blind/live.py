import heapq
from turtle import forward 

def solution(food_times, k):
    if sum(food_times) <= k:
        return - 1

    previous = 0
    total = len(food_times)

    heap = []

    for i in range(len(food_times)):
        heapq.heappush(heap, [food_times[i], i])

    #previois를 더해주지 않아서 문제가 됨
    while heap:
        min_time, idx = heapq.heappop(heap)
        min_time -= previous

        if min_time * total < k:
            previous += min_time
            food_times[idx] = 0

            k -= min_time * total
        else:
            need_forward = k % total
            forward = 0

            for idx in range(len(food_times)):
                if food_times[idx]:
                    if forward == need_forward:
                        answer = idx + 1
                    
                    forward += 1
            
            break

        total -= 1

    return answer

if __name__ == "__main__":
    food_times = [3, 1, 2]
    k = 5

    print(solution(food_times, k))