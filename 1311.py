import unittest

person = []
work_cache = []
n = 1

class TestMethod(unittest.TestCase):
    def test_add_bit_idx(self):
        cache_key = add_bit_idx(0, 0)
        self.assertEqual(cache_key, 1)

        cache_key = add_bit_idx(0, 1)
        self.assertEqual(cache_key, 2)

def add_bit_idx(cache_key, idx):
    bit_cached = cache_key | (1 << idx)
    return bit_cached


def get_min_work_value(person_idx, cache_key):
    global person
    global work_cache
    global n

    if person_idx >= n:
        return 0

    if cache_key in work_cache[person_idx]:       #key 값을 가지고 있으면 그 값을 리턴 
        return work_cache[person_idx][cache_key]

    work_cache[person_idx][cache_key] = 987654321

    for work in range(n):      #일
        if 0 == (cache_key & (1 << work)):
            work_cache[person_idx][cache_key] = min(work_cache[person_idx][cache_key], person[person_idx][work] + get_min_work_value(person_idx + 1, cache_key | (1 << work)))

    return work_cache[person_idx][cache_key]
    



if __name__ == "__main__":
    # unittest.main()

    n = int(input())

    work_cache = [{} for _ in range(n)]
    key = 0
    for _ in range(n):
        person.append(list(map(int, input().split())))


    print(get_min_work_value(0, 0))
    

