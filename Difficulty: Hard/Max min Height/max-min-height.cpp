class Solution {
  public:
    bool isPossible(vector<int> &arr, int k, int w, int target) {
        int n = arr.size();
        vector<int> water(n + 1, 0); // Difference array
        long long ops = 0, add = 0;

        for (int i = 0; i < n; ++i) {
            add += water[i];
            int current = arr[i] + add;

            if (current < target) {
                int delta = target - current;
                ops += delta;
                if (ops > k) return false;
                add += delta;
                if (i + w < n) water[i + w] -= delta;
            }
        }
        return true;
    }

    int maxMinHeight(vector<int> &arr, int k, int w) {
        int low = *min_element(arr.begin(), arr.end());
        int high = low + k;

        int result = low;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (isPossible(arr, k, w, mid)) {
                result = mid;
                low = mid + 1; // try higher
            } else {
                high = mid - 1;
            }
        }
        return result;
    }
};
