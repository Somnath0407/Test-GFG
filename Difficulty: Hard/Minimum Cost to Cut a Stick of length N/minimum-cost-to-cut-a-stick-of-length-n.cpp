class Solution {
public:
    int minCutCost(int n, vector<int>& cuts) {
        int m = cuts.size();
        vector<int> c = cuts;
        c.push_back(0);
        c.push_back(n);
        sort(c.begin(), c.end());

        vector<vector<int>> dp(m+2, vector<int>(m+2, 0));
        for(int len = 2; len < m+2; len++){
            for(int i = 0; i + len < m+2; i++){
                int j = i + len;
                dp[i][j] = 1e9;
                for(int k = i+1; k < j; k++){
                    int cost = c[j] - c[i] + dp[i][k] + dp[k][j];
                    dp[i][j] = min(dp[i][j], cost);
                }
            }
        }
        return dp[0][m+1];
    }
};
