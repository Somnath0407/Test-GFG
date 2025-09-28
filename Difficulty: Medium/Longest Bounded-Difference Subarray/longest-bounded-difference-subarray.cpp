class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
    int n = arr.size();
    int bestLen = 0, bestL = 0;
    for (int i = 0; i < n; i++) {
        int mn = arr[i], mx = arr[i];
        for (int j = i; j < n; j++) {
            mn = min(mn, arr[j]);
            mx = max(mx, arr[j]);
            if (mx - mn <= x) {
                if (j - i + 1 > bestLen) {
                    bestLen = j - i + 1;
                    bestL = i;
                }
            } else break;
        }
    }
    return vector<int>(arr.begin() + bestL, arr.begin() + bestL + bestLen);
    }
};