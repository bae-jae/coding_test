from itertools import permutations

def validate(user, ban):
    if len(user) != len(ban):
        return False
    else:
        for i, j in zip(user, ban):
            if j == '*':
                continue
            if i != j:
                return False
        return True


def solution(user_ids, banned_id):
    answer = []
    
    for i in permutations(user_ids, len(banned_id)):
        is_banned = True

        for user_id, ban_id in zip(i, banned_id):
            if not validate(user_id, ban_id):
                is_banned = False

        if is_banned:
            if not set(i) in answer:
                answer.append(set(i))


    return len(answer)


if __name__ == "__main__":
    user_id = 	["frodo", "fradi", "crodo", "abc123", "frodoc"]
    ban_id = ["*rodo", "*rodo", "******"]

    print(solution(user_id, ban_id) == 2)