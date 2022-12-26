
def set_occupancy(rooms, room_number):
    _, next_room_number = rooms[room_number]
    rooms[room_number][0] = True

def get_next_room_number(rooms, room_number):
    is_occupancy, next_room_number = rooms.get(room_number, [False, room_number])

    if not is_occupancy:
        return room_number
    else:
        next_room_number = get_next_room_number(rooms, next_room_number)     #다음 방 번호
        rooms[room_number][1] = next_room_number
    
    return next_room_number

def solution(k, request_room_numbers):
    answer = []
    
    rooms = {}  #점유, 다음 방번호
    max_room_num = -1
    for request_room_number in request_room_numbers:
        max_room_num = max(max_room_num, request_room_number)
        rooms[request_room_number] = [False, request_room_number + 1]


    for request_room_number in request_room_numbers:
        occupancy, next_room_number = rooms[request_room_number]

        if not occupancy:
            set_occupancy(rooms, request_room_number)
            answer.append(request_room_number)
        else:
            cand_number = get_next_room_number(rooms, next_room_number)
            rooms[cand_number] = [True, cand_number + 1]
            answer.append(cand_number)

    return answer


if __name__ == "__main__":
    k = 10
    room_number = [1,3,4,1,3,1] 
    result = [1,3,4,2,5,6]

    print(solution(k, room_number))