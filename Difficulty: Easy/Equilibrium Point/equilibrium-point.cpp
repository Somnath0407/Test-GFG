class Solution {
  public:
    int findEquilibrium(vector<int> &arr) {
        long long total = accumulate(arr.begin(), arr.end(), 0LL);
        long long left = 0;
        for (int i = 0; i < arr.size(); i++) {
            total -= arr[i];
            if (left == total) return i;
            left += arr[i];
        }
        return -1;
    }
};
