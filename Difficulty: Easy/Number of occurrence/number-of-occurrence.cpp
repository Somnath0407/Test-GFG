class Solution {
public:
    int countFreq(vector<int>& arr, int target) {
        int n = arr.size();
        int first = lower_bound(arr.begin(), arr.end(), target) - arr.begin();
        if(first == n || arr[first] != target) return 0;
        int last = upper_bound(arr.begin(), arr.end(), target) - arr.begin() - 1;
        return last - first + 1;
    }
};
