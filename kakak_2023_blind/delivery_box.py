def get_longest_site(site, n):
    move = 0

    for point_idx in range(n, -1, -1):
        if site[point_idx] > 0:
            move = point_idx
            break
    
    return move

def caculate_spend_day(deliveries, cap):
    needed_day = [0] * len(deliveries)
    n = len(deliveries)
    max_cap = cap
    day = 1

    site_idx = n - 1
    
    while 0 <= site_idx:
        if deliveries[site_idx] == 0:
            site_idx -= 1
            continue

        #이번 장소에 있는 물건은 충분히 다을 수 있음
        if deliveries[site_idx] <= cap:
            cap -= deliveries[site_idx]
            deliveries[site_idx] = 0
            needed_day[site_idx] = day

        #이번 장소에 있는 물건은 담을 수 없음
        else:
            deliveries[site_idx] = deliveries[site_idx] - cap #당믈 수 있는 만큼 담아서 출발
            day += 1                           
            cap = max_cap
    
    return needed_day

def calculated_move(result, n):
    answer = 0
    spended_day = 0

    for i in range(n, 0, -1):
        day = result[i] - spended_day

        if day <= 0:
            continue

        spended_day += day
        print(i)
        answer += day * (i * 2)

    return answer

def solution(cap, n, deliveries, pickups):
    answer = 0

    deliveries.insert(0, 0)
    pickups.insert(0, 0)

    calc_delivers = caculate_spend_day(deliveries, cap)
    calc_pickups = caculate_spend_day(pickups, cap)

    result = []

    for i in range(len(calc_delivers)):
        result.append(max(calc_delivers[i], calc_pickups[i]))    

    answer = calculated_move(result, n)
    return answer

if __name__ == "__main__":
    cap = 4	
    n = 6	
    deliveries =[1, 0, 3, 1, 2, 0]
    pickups = [0, 3, 0, 4, 0, 1]	
    result = 16

    print(solution(cap, n, deliveries, pickups))