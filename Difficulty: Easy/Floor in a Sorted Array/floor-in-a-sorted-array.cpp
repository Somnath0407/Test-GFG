class Solution {
public:
    int findFloor(vector<int>& arr, int x) {
        int l = 0, r = arr.size() - 1, res = -1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (arr[m] <= x) {
                res = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return res;
    }
};