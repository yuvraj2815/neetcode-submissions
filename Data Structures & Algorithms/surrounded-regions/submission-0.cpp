class Solution {
    int dr[4] = {0, -1, 0, 1};
    int dc[4] = {-1, 0, 1, 0};
public:
    void dfs(int r, int c, vector<vector<char>>& board) {
        board[r][c] = 'S';
        for (int k = 0; k < 4; k++) {
            int x = r + dr[k];
            int y = c + dc[k];

            if (x >= 0 && y >= 0 && x < (int)board.size() && y < (int)board[0].size()
                && board[x][y] == 'O')
                dfs(x, y, board);
        }
    }

    void solve(vector<vector<char>>& board) {
        int row = board.size(), col = board[0].size();

        for (int r = 0; r < row; r++) {
            if (board[r][0] == 'O') dfs(r, 0, board);
            if (board[r][col - 1] == 'O') dfs(r, col - 1, board);
        }
        for (int c = 0; c < col; c++) {
            if (board[0][c] == 'O') dfs(0, c, board);
            if (board[row - 1][c] == 'O') dfs(row - 1, c, board);
        }

        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                if (board[r][c] == 'O') board[r][c] = 'X';
                else if (board[r][c] == 'S') board[r][c] = 'O';
            }
        }
    }
};