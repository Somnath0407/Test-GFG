class Solution {
  public:
    bool canFinish(vector<int>& arr, int k, int s) {
        long long hours = 0;
        for (int x : arr) {
            hours += (x + s - 1) / s;  
            if (hours > k) return false;
        }
        return true;
    }

    int kokoEat(vector<int>& arr, int k) {
        int low = 1, high = 0;
        for (int x : arr) high = max(high, x);

        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canFinish(arr, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
