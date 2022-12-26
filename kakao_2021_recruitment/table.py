from collections import deque

def get_next_pos(cache, my_pos, mv_cnt=1, foward=True):

    for _ in range(mv_cnt):
        if foward:
            next_pos = cache[my_pos][1]
        else:
            next_pos = cache[my_pos][0]

        my_pos = next_pos
    
    return my_pos

def solution(n, my_pos, cmds):
    answer = ''

    origin_array = [[i, True] for i in range(n)]
    cache_table = {}        #o back 1 forward
    
    for i in range(n):
        cache_table[i] = [i -1, i + 1]

    cache_table[0] = [None , 1]
    cache_table[n-1] = [n-2, None]

    remove_queue = deque()

    for cmd in cmds:
        if len(cmd.split()) > 1:
            mv, mv_cnt = cmd.split()
            mv_cnt = int(mv_cnt)

            if mv == "D":
                next_pos = get_next_pos(cache_table, my_pos, mv_cnt)     #앞으로 전진 None 확률 없음
            else:
                next_pos = get_next_pos(cache_table, my_pos, mv_cnt, foward=False)

            my_pos = next_pos
        else:
            if cmd[0] == 'C':
                origin_array[my_pos][1] = False
                back_pos, forward_pos = cache_table[my_pos]

                #몸통
                if back_pos != None and forward_pos != None:
                    cache_table[back_pos][1] = forward_pos
                    cache_table[forward_pos][0] = back_pos
                else:
                    #머리
                    if forward_pos != None: #back은 None임
                        cache_table[forward_pos][0] = None
                    else: #꼬리
                        cache_table[back_pos][1] = None

                remove_queue.append((back_pos, my_pos, forward_pos))

                if forward_pos == None:
                    my_pos = back_pos
                else:
                    my_pos = forward_pos

            if cmd[0] == "Z":
                back_pos, pos, forward_pos = remove_queue.pop()
                
                #몸통
                if back_pos != None and forward_pos != None:
                    cache_table[forward_pos][0] = pos
                    cache_table[back_pos][1] = pos
                else:
                    #머리
                    if forward_pos != None: #back은 None임
                        cache_table[forward_pos][0] = pos
                    else: #꼬리
                        cache_table[back_pos][1] = pos


                origin_array[pos][1] = True

        # print("my pos is", my_pos)
        # print(origin_array)
        # print(cache_table)

    answer = ''

    for _, is_alive in origin_array:
        if is_alive:
            answer += "O"
        else:
            answer += "X"

    return answer




if __name__ == "__main__":
    n = 8
    k = 2
    cmd = ["D 2","C","U 3","C","D 4","C","U 2","Z","Z","U 1","C"]

    print(solution(n, k, cmd))