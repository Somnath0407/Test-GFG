class Solution {
  public:
    int maxProfit(vector<vector<int>> &jobs) {
        sort(jobs.begin(), jobs.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });
        
        int n = jobs.size();
        vector<int> dp(n), end(n);
        
        for (int i = 0; i < n; i++) end[i] = jobs[i][1];
        dp[0] = jobs[0][2];
        
        for (int i = 1; i < n; i++) {
            int cur = jobs[i][2];
            int j = upper_bound(end.begin(), end.end(), jobs[i][0]) - end.begin() - 1;
            if (j >= 0) cur += dp[j];
            dp[i] = max(dp[i - 1], cur);
        }
        
        return dp[n - 1];
    }
};
