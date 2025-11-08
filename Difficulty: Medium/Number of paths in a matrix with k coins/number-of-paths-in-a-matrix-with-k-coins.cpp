class Solution {
public:
    int n, m;
    int dp[101][101][101]; 
    int paths(vector<vector<int>>& mat, int i, int j, int k) {
        if (i >= n || j >= m) return 0;
        if (k < 0) return 0;
        if (i == n - 1 && j == m - 1)
            return (k == mat[i][j]);
        if (dp[i][j][k] != -1) return dp[i][j][k];
        int rem = k - mat[i][j];
        int down = paths(mat, i + 1, j, rem);
        int right = paths(mat, i, j + 1, rem);
        return dp[i][j][k] = down + right;
    }
    int numberOfPath(vector<vector<int>>& mat, int k) {
        n = mat.size();
        m = mat[0].size();
        memset(dp, -1, sizeof(dp));
        return paths(mat, 0, 0, k);
    }
};
