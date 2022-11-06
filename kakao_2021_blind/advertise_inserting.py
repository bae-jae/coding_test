def chagne_time_to_sec(time):
    h, m, s = map(int, time.split(":"))

    return h * 3600 + m * 60 + s

def change_sec_to_time(sec):
    m, s = divmod(sec, 60)
    h, m = divmod(m, 60)

    h, m, s = map(str, [h,m,s])

    h = h.zfill(2)
    m = m.zfill(2)
    s = s.zfill(2)

    time = ":".join([h,m,s])
    return  time



def sum_watching_player(psum_of_time, logs):

    for log in logs:
        start_time, end_time = map(chagne_time_to_sec, log.split("-"))

        psum_of_time[start_time] = psum_of_time[start_time] + 1
        psum_of_time[end_time] = psum_of_time[end_time] -1


    for i in range(1, len(psum_of_time)):
        psum_of_time[i] = psum_of_time[i] + psum_of_time[i - 1]

def solution(play_time, adv_time, logs):
    answer = ''

    play_time_sec = chagne_time_to_sec(play_time)
    psum_of_time = [0] * (play_time_sec + 1)

    adv_time_sec = chagne_time_to_sec(adv_time)

    sum_watching_player(psum_of_time, logs)

    max_watching_time = 0
    watching_time = 0
    start_time_sec = 0

    for i in range(1, adv_time_sec):
        max_watching_time += psum_of_time[i-1]

    watching_time = max_watching_time
        
    for i in range(adv_time_sec, len(psum_of_time)):
        watching_time = watching_time + psum_of_time[i - 1] - psum_of_time[i - adv_time_sec - 1]

        if max_watching_time < watching_time:
            max_watching_time = watching_time
            start_time_sec = i - adv_time_sec

    start_time = change_sec_to_time(start_time_sec)

    return start_time




if __name__ == "__main__":
    play_time = "99:59:59"
    adv_time = "25:00:00"
    logs = ["69:59:59-89:59:59", "01:00:00-21:00:00", "79:59:59-99:59:59", "11:00:00-31:00:00"]

    print(solution(play_time, adv_time, logs))
