from collections import deque

def time_to_sec(time):
    hour, min = map(int, time.split(':'))

    hour = hour * 3600
    min = min * 60

    return hour + min

def sec_to_time(sec):
    hour = sec // 3600
    min = (sec % 3600) // 60


    return str(hour).rjust(2,"0") + ":" + str(min).rjust(2,"0")

def solution(n, t, m, timetable):
    answer = ''

    time_table = list(map(time_to_sec, timetable))
    time_table.sort()
    time_table = deque(time_table)

    bus_start_time = time_to_sec("09:00")   #버스 시작 시간
    jump_time = t * 60

    occupant = 0
    bus_go = 1

    #항상 마지막 버스를 노린다
    while time_table and bus_go < n:
        arrive_time = time_table.popleft()

        if arrive_time <= bus_start_time:
            occupant += 1

            if occupant == m:
                bus_go += 1
                occupant = 0
                bus_start_time += jump_time
        else:
            bus_go += 1
            bus_start_time += jump_time
            time_table.appendleft(arrive_time)



    #경쟁해야 하는 인원만 남아있음 and 버스가 한대 남아 있음은 보장함
    #대기줄이 없다

    occupant = 0
    if not time_table:
        return sec_to_time(bus_start_time)

    while time_table:
        arrive_time = time_table.popleft()

        if arrive_time <= bus_start_time:
            if occupant + 1 == m:
                return sec_to_time(arrive_time - 1)
            occupant += 1
        else:
            break
    
    return sec_to_time(bus_start_time)

if __name__ == "__main__":
   n=2
   t=10	
   m=2	
   time_table=["09:10", "09:09", "08:00"]
   print(solution(n, t, m, time_table))