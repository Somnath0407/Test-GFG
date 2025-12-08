class Solution {
public:
    string matrixChainOrder(vector<int> &arr) {
        int n = arr.size() - 1;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        vector<vector<int>> split(n, vector<int>(n, -1));

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                dp[i][j] = INT_MAX;
                for (int k = i; k < j; k++) {
                    long long cost = dp[i][k] + dp[k+1][j] + 1LL * arr[i] * arr[k+1] * arr[j+1];
                    if (cost < dp[i][j]) {
                        dp[i][j] = cost;
                        split[i][j] = k;
                    }
                }
            }
        }

        string res;
        function<void(int,int)> build = [&](int i, int j){
            if (i == j) {
                res.push_back('A' + i);
                return;
            }
            res.push_back('(');
            build(i, split[i][j]);
            build(split[i][j] + 1, j);
            res.push_back(')');
        };

        build(0, n - 1);
        return res;
    }
};
