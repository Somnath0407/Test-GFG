class Solution {
public:
    int fun(vector<int>& arr, int target, int n, vector<vector<int>>& dp, int i) {
        if (i == n) {
            if (target == 0) return 1;
            return 0;
        }
        if (dp[i][target] != -1) return dp[i][target];
        if (arr[i] == 0) {
            if (target == 0) {
                int pick = fun(arr, target, n, dp, i + 1);
                int nonpick = fun(arr, target, n, dp, i + 1);
                return dp[i][target] = pick + nonpick;
            }
        }
        if (arr[i] > target) return dp[i][target] = fun(arr, target, n, dp, i + 1);
        int pick = fun(arr, target - arr[i], n, dp, i + 1);
        int nonpick = fun(arr, target, n, dp, i + 1);
        return dp[i][target] = pick + nonpick;
    }
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        return fun(arr, target, n, dp, 0);
    }
};