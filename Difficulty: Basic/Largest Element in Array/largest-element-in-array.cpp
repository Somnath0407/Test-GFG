class Solution {
  public:
    int largest(vector<int> &arr) {
        int n = arr.size();
        int ans = arr[0];
        for (int i = 1; i < n; i++) {
            ans = max(ans, arr[i]);
        }
        return ans;
    }
};
