
class Solution {
public:
    vector<int> farMin(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, -1), suffMin(n);
        suffMin[n-1] = arr[n-1];
        for (int i = n-2; i >= 0; i--) {
            suffMin[i] = min(arr[i], suffMin[i+1]);
        }
        for (int i = 0; i < n; i++) {
            int l = i+1, r = n-1;
            while (l <= r) {
                int mid = (l+r)/2;
                if (suffMin[mid] < arr[i]) {
                    ans[i] = mid;  
                    l = mid + 1;  
                } else {
                    r = mid - 1;
                }
            }
        }
        return ans;
    }
};
