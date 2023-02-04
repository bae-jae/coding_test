from itertools import product

def solution(users, emoticons):
    answer = [0, 0]
    discount = [0.1, 0.2, 0.3, 0.4]

    for pick in product(discount, repeat=len(emoticons)):

        can_get_moeny = 0
        join_emoji_club = 0

        for user in users:
            discount_need = user[0] / 100
            upper_limit = user[1]
            total_money = 0

            for sale, price in zip(pick, emoticons):
                if discount_need <= sale:
                    total_money += price *  (1 - sale)
            
            if upper_limit <= total_money:
                total_money = 0
                join_emoji_club += 1
            
            can_get_moeny += total_money
        
        answer = max(answer, [join_emoji_club, can_get_moeny])

    return answer



if __name__ == "__main__":
    users = [[40, 10000], [1, 10000]]
    emoticons = [7000, 9000]
    result = [1, 5400]

    print(solution(users, emoticons))
