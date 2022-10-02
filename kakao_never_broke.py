
def make_psum(board):
    psum = [[0] * len(board[0]) for _ in range(len(board))]
    psum[0][0] = board[0][0]

    #첫 row
    for i in range(1, len(board[0])):
        psum[0][i] = board[0][i] + psum[0][i - 1]

    #첫 col
    for i in range(1, len(board)):
        psum[i][0] = board[i][0] + psum[i - 1][0]

    
    for i in range(1, len(board)):
        for j in range(1, len(board[0])):
            psum[i][j] = board[i][j] + psum[i][j - 1] + psum[i - 1][j] - psum[i - 1][j - 1]

    return psum

def solution(board, skills):
    answer = 0

    skills_board = [[0] * len(board[0]) for _ in range(len(board))]

    for skill in skills:
        type, row_x, row_y, col_x, col_y, deg = skill

        if type == 1:
            deg = -deg

        skills_board[row_x][row_y] += deg

        if col_x + 1 < len(board):
            skills_board[col_x + 1][row_y] += (-deg)

        if col_y + 1 < len(board[0]):
            skills_board[row_x][col_y + 1] += (-deg)

        
        if col_x + 1 < len(board) and col_y + 1 < len(board[0]):
            skills_board[col_x + 1][col_y + 1] += (deg)

        print(skills_board)
    
    psum_skill_board = make_psum(skills_board)
    print(psum_skill_board)

        
    answer = 0

    for row in range(len(board)):
        for col in range(len(board[0])):
            board[row][col] += psum_skill_board[row][col]

            if board[row][col] > 0:
                answer += 1

    print(board)
    
    return answer


if __name__ == "__main__":
    board = [[1,2,3],[4,5,6],[7,8,9]]
    skill = [[1,1,1,2,2,4],[1,0,0,1,1,2],[2,2,0,2,0,100]]

    solution(board, skill)