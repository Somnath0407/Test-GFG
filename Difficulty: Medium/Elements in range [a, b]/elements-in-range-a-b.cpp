class Solution {
  public:
    vector<int> cntInRange(vector<int> &arr, vector<vector<int>> &queries) {
        map<int, int> mp;

        // frequency
        for (int x : arr) {
            mp[x]++;
        }

        // prefix sum in map
        int sum = 0;
        for (auto &it : mp) {
            sum += it.second;
            it.second = sum;
        }

        vector<int> ans;

        for (auto &q : queries) {
            int a = q[0], b = q[1];

            int cntB = 0, cntA = 0;

            auto itB = mp.upper_bound(b);
            if (itB != mp.begin()) {
                --itB;
                cntB = itB->second;
            }

            auto itA = mp.lower_bound(a);
            if (itA != mp.begin()) {
                --itA;
                cntA = itA->second;
            }

            ans.push_back(cntB - cntA);
        }

        return ans;
    }
};
