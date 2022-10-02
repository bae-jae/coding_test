#09 15 시작
#10 15 죵료

#변수명을 제대로 정의하고, 중복된 부분을 찾아보자
#코드는 일관성 있게 짜는게 좋겠다 디버깅을 위해서
import math
def get_minute(time):
    h, m = map(int, time.split(":"))
    m += h * 60

    return m

def get_fee(total_time, fees):
    init_time = fees[0]
    init_money = fees[1]
    per_min = fees[2]
    m_per_money = fees[3]

    if total_time <= init_time:
        return init_money

    
    return init_money + int(math.ceil((total_time - init_time) / per_min)) * m_per_money
    
    

def solution(fees, records):
    answer = []
    
    parking_lot = {}
    parking_money = {}

    for record in records:
        time, number, state = record.split()

        if state == "IN":
            if not number in parking_lot:
                parking_lot[number] = [state, time, 0]
            else:
                parking_lot[number] = [state, time, parking_lot[number][2]]
        else:
            _, in_time, total_use_time = parking_lot[number]

            in_time = get_minute(in_time)
            out_time = get_minute(time)

            time_diff = out_time - in_time

            if not number in parking_money:
                parking_money[number] = 0

            parking_lot[number] = [state, get_minute(time), total_use_time + time_diff]

    for parking_lot_status in parking_lot.items():
        number, car_use_status = parking_lot_status
        state, in_time, total_use_time = car_use_status

        if state == "IN":
            state, in_time, total_use_time = parking_lot[number]

            
            in_time = get_minute(in_time)
            out_time = get_minute("23:59")

            time_diff = out_time - in_time

            if not number in parking_money:
                parking_money[number] = 0

            parking_lot[number] = [state, get_minute("22:56"), total_use_time + time_diff]
    
    answer = []
    for parking_lot_status in parking_lot.items():
        number, car_use_status = parking_lot_status
        state, time, total_use_time = car_use_status

        answer.append([number, get_fee(total_use_time, fees)])

    answer.sort()
    answer = list(zip(*answer))[1]
    return answer


if __name__ == "__main__":
    fees = [180, 5000, 10, 600]
    records = ["05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT"]
    solution(fees, records)