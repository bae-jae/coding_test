n = 0
k = 0
solve_prob = 0
weight_kit = []

def solve(weight_kit_bool, weight):
    global n, k, solve_prob, weight_kit

    can_ans = 1

    for i in range(len(weight_kit_bool)):
        if weight_kit_bool[i] == 0:
            can_ans = 0
            break

    if can_ans:
        solve_prob += 1
        return


    for i in range(len(weight_kit_bool)):
        next_weight = weight - k + weight_kit[i]

        if weight_kit_bool[i] == 0 and next_weight >= 500:
            weight_kit_bool[i] = 1
            solve(weight_kit_bool, next_weight)
            weight_kit_bool[i] = 0
            


    

if __name__ == "__main__":
    n, k = map(int, input().split())

    weight_kit = list(map(int, input().split()))
    weight_kit_bool = list = [0] * (n)
    
    solve(weight_kit_bool, 500)
    print(solve_prob)
