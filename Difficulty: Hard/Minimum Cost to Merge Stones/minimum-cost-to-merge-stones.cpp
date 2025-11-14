class Solution {
public:
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        if ((n - 1) % (k - 1) != 0) return -1;
        vector<int> pre(n + 1, 0);
        for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + stones[i];
        const int INF = 1e9;
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int len = k; len <= n; len++) {
            for (int l = 0; l + len - 1 < n; l++) {
                int r = l + len - 1;
                dp[l][r] = INF;

                for (int m = l; m < r; m += k - 1)
                    dp[l][r] = min(dp[l][r], dp[l][m] + dp[m + 1][r]);

                if ((len - 1) % (k - 1) == 0)
                    dp[l][r] += pre[r + 1] - pre[l];
            }
        }
        return dp[0][n - 1];
    }
};
