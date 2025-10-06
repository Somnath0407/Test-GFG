class Solution {
  public:
    int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    
    bool isSafe(int x, int y, vector<vector<int>>& board, int n) {
        return (x >= 0 && y >= 0 && x < n && y < n && board[x][y] == -1);
    }
    
    bool solve(int x, int y, int move, vector<vector<int>>& board, int n) {
        if (move == n * n) return true;
        
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (isSafe(nx, ny, board, n)) {
                board[nx][ny] = move;
                if (solve(nx, ny, move + 1, board, n))
                    return true;
                board[nx][ny] = -1;
            }
        }
        return false;
    }

    vector<vector<int>> knightTour(int n) {
        vector<vector<int>> board(n, vector<int>(n, -1));
        board[0][0] = 0;
        if (!solve(0, 0, 1, board, n)) return {};
        return board;
    }
};
