class Solution {
public:
    vector<int> leaders(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans;
        int mx = -1;
        for (int i = n - 1; i >= 0; i--) {
            if (arr[i] >= mx) {
                ans.push_back(arr[i]);
                mx = arr[i];
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
