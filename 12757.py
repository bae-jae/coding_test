
import heapq
import bisect

def binary_search(cand_list, target):
    """항상 target과 같은 index를 반환함 해당하는 값이 없다면 len(cand_list)를 return

    Args:
        cand_list (_type_): _description_
        target (_type_): _description_

    Returns:
        _type_: _description_
    """
    lo = -1                     #lo는 target보다 항상 작음 
    high = len(cand_list)

    while lo + 1 < high:        #lo + 1 < high 중간이 있다는 것을 증명
        mid = int((lo + high) / 2)

        if cand_list[mid][0] < target:
            lo = mid            #lo는 target보다 항상 작음 
        else:       #cand_list[mid] >= target
            high = mid  

    return high

    

def tide_search(cand_list, mid_index, target_key, k):
    """ cand_list[mid_index - 1][0] < target <= cand_list[mid_index][0]

    Args:
        cand_list (_type_): DB 배얄
        mid (_type_): cand_key에 해당하는 index
        target_key (_type_): 찾기를 원하는 값
        k (_type_): 허용 범위

    Returns:
        _type_: _description_
    """

    if mid_index == 0:
        #mid_index가 target_key보다 같거나 큼으로 위에 있는 것은 계산할 필요가 없음
        if abs(cand_list[mid_index][0] - target_key) <= k:              #해당하는 구간안에 속하면 
            return mid_index
        return -1                                                       #위로는 당연히 더 커지기 때문에 검사할 부분이 없음

    #마지막 index 해당 key 값과 같은 값이 존재하지 않았음
    if len(cand_list) == mid_index:       
        if abs(cand_list[mid_index - 1][0] - target_key) <= k:      #밑에 키를 가지고 검사함
            return mid_index - 1
        return -1

    "index의 범위는 1 <= <= len()-1"

    origin_key = abs(cand_list[mid_index][0] - target_key) 
    left_key = abs(cand_list[mid_index - 1][0] - target_key)
    
    if origin_key <= k:

        if left_key == origin_key:
            return -2

        "orgin_key가 k안에 들어옴으로 lefe_key가 oring보다 작으면 더 근접함"
        if left_key < origin_key:
            return mid_index - 1
        else:
            return mid_index
    else: #origin_key > k
        if left_key <= k:
            return mid_index - 1
    
    return -1

if __name__ == "__main__":
    n, m, k = map(int, input().split())

    cand = []

    for _ in range(n):
        key, value = map(int, input().split())
        bisect.insort(cand,[key, value])

    for _ in range(m):
        query = list(map(int, input().split()))

        if query[0] == 1:
            bisect.insort(cand,[query[1], query[2]])
        
        if query[0] == 2:
            index = binary_search(cand, query[1])
            index = tide_search(cand, index, query[1], k)

            if index >= 0:
                cand[index][1] = query[2]

        if query[0] == 3:
            index = binary_search(cand, query[1])
            index = tide_search(cand, index, query[1], k)

            if index == -2:
                print("?")
            elif index == -1:
                print(-1)
            else:
                print(cand[index][1])

        print(cand)