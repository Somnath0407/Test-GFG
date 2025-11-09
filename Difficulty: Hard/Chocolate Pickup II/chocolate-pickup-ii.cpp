class Solution {
public:
    int n;
    int dp[101][101][101];
    int solve(vector<vector<int>>& mat, int r1, int c1, int r2) {
        int c2 = r1 + c1 - r2; 
        if (r1 >= n || c1 >= n || r2 >= n || c2 >= n || 
            mat[r1][c1] == -1 || mat[r2][c2] == -1)
            return INT_MIN;
        if (r1 == n - 1 && c1 == n - 1) 
            return mat[r1][c1]; 
        if (dp[r1][c1][r2] != -1) 
            return dp[r1][c1][r2];
        int result = mat[r1][c1];
        if (r1 != r2 || c1 != c2)
            result += mat[r2][c2]; 
        int next = max({
            solve(mat, r1 + 1, c1, r2 + 1), 
            solve(mat, r1, c1 + 1, r2),     
            solve(mat, r1 + 1, c1, r2),     
            solve(mat, r1, c1 + 1, r2 + 1)  
        });
        result += next;
        return dp[r1][c1][r2] = result;
    }
    int chocolatePickup(vector<vector<int>>& mat) {
        n = mat.size();
        memset(dp, -1, sizeof(dp));
        int ans = solve(mat, 0, 0, 0);
        return max(0, ans);
    }
};
