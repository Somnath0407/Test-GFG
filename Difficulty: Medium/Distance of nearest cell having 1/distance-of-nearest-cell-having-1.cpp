class Solution {
  public:
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> ans(n, vector<int>(m, -1));
        queue<pair<int, int>> q;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k], ny = y + dy[k];
                if (nx >= 0 && ny >= 0 && nx < n && ny < m && ans[nx][ny] == -1) {
                    ans[nx][ny] = ans[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
        return ans;
    }
};
