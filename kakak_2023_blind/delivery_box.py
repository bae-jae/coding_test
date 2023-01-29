def get_longest_site(site, n):
    move = 0

    for point_idx in range(n, -1, -1):
        if site[point_idx] > 0:
            move = point_idx
            break
    
    return move

def remove_box(deliveries, longest_point, cap):
    for i in range(longest_point, 0, -1):
        if cap == 0:
            break

        if cap >= deliveries[i]:
            cap -= deliveries[i]
            deliveries[i] = 0
        else:
            deliveries[i] = deliveries[i] - cap
            cap = 0

def solution(cap, n, deliveries, pickups):
    answer = 0

    deliveries.insert(0, 0)
    pickups.insert(0, 0)

    
    while True:
        longest_deliver_point = get_longest_site(deliveries, n)
        longest_pick_point = get_longest_site(pickups, n)

        move = max(longest_deliver_point, longest_pick_point)

        if move == 0:
            break

        n = move
        answer += (move * 2)

        remove_box(deliveries, longest_deliver_point, cap)
        remove_box(pickups, longest_pick_point, cap)

    return answer

if __name__ == "__main__":
    cap = 4	
    n = 5	
    deliveries =[1, 0, 3, 1, 2]
    pickups = [0, 3, 0, 4, 0]	
    result = 16

    print(solution(cap, n, deliveries, pickups))