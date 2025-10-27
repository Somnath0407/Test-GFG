class Solution {
  public:
    vector<vector<int>> kSmallestPair(vector<int> &arr1, vector<int> &arr2, int k) {
        vector<vector<int>> res;
        if (arr1.empty() || arr2.empty() || k == 0) return res;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> p;
        for (int i = 0; i < arr1.size() && i < k; ++i)
            p.push({arr1[i] + arr2[0], i, 0});
        while (!p.empty() && res.size() < k) {
              vector<int> top = p.top();
              p.pop();
            int i = top[1], j = top[2];
            res.push_back({arr1[i], arr2[j]});
            if (j + 1 < arr2.size())
                p.push({arr1[i] + arr2[j + 1], i, j + 1});
        }
        return res;
    }
};
