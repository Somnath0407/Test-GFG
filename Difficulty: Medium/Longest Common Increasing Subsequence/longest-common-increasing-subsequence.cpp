class Solution {
public:
    int LCIS(vector<int> &a, vector<int> &b) {
        int n = a.size(), m = b.size();
        vector<int> dp(m, 0);
        for (int i = 0; i < n; i++) {
            int cur = 0;
            for (int j = 0; j < m; j++) {
                if (a[i] == b[j]) dp[j] = max(dp[j], cur + 1);
                else if (a[i] > b[j]) cur = max(cur, dp[j]);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};
