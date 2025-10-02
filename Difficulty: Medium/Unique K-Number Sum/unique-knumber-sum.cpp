class Solution {
public:
    vector<vector<int>> combinationSum(int n, int k) {
        vector<vector<int>> ans;
        vector<int> path;
        dfs(1, k, 0, n, path, ans);
        return ans;
    }

private:
    void dfs(int start, int k, int sum, int target, vector<int>& path, vector<vector<int>>& ans) {
        if (k == 0) {
            if (sum == target) ans.push_back(path);
            return;
        }
        if (start > 9) return;
        long long minPossible = sum + (long long)k * start + (long long)k * (k - 1) / 2;
        if (minPossible > target) return;
        long long maxPossible = sum + (long long)k * 9 - (long long)k * (k - 1) / 2;
        if (maxPossible < target) return;
        for (int i = start; i <= 9; ++i) {
            if (k == 1 && sum + i > target) break;
            path.push_back(i);
            dfs(i + 1, k - 1, sum + i, target, path, ans);
            path.pop_back();
        }
    }
};
