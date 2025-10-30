class Solution {
  public:
    void dfs(int i, int j, vector<vector<char>>& grid, int n, int m) {
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] != 'O')
            return;
        grid[i][j] = '#';
        dfs(i+1, j, grid, n, m);
        dfs(i-1, j, grid, n, m);
        dfs(i, j+1, grid, n, m);
        dfs(i, j-1, grid, n, m);
    }
    void fill(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 'O') 
                dfs(i, 0, grid, n, m);
            if (grid[i][m-1] == 'O') 
                dfs(i, m-1, grid, n, m);
        }
        for (int j = 0; j < m; j++) {
            if (grid[0][j] == 'O') 
                dfs(0, j, grid, n, m);
            if (grid[n-1][j] == 'O') 
                dfs(n-1, j, grid, n, m);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'O')
                    grid[i][j] = 'X';
                if (grid[i][j] == '#') 
                    grid[i][j] = 'O';
            }
        }
    }
};
