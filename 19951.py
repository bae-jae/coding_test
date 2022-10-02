
def make_psum(arr):

    psum = []
    psum.append(arr[0])

    for i in range(1, len(arr)):
        psum.append(psum[i - 1] + arr[i])

    return psum


def solution(board, order_by_superior):
    record_board = [0] * len(board)


    for s, e, d in order_by_superior:
        record_board[s - 1] += d

        if e != len(board):
            record_board[e] += -d

    result_psum = make_psum(record_board)
    answer = [x + y for x, y in zip(board,result_psum)]

    return answer

if __name__ == "__main__":
    n, m = map(int, input().split())
    board = list(map(int, input().split()))

    order_by_superior = []

    for _ in range(m):
        order_by_superior.append(list(map(int, input().split())))

    answer = solution(board, order_by_superior)

    for i in answer:
        print(i, end=" ")

# 10 3
# 1 2 3 4 5 -1 -2 -3 -4 -5
# 1 5 -3
# 6 10 5
# 2 7 2