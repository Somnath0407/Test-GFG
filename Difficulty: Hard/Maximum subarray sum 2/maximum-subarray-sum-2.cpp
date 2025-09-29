class Solution {
  public:
    int maxSubarrSum(vector<int>& arr, int a, int b) {
        int n = arr.size();
        vector<long long> ps(n + 1, 0);
        for (int i = 0; i < n; i++) ps[i + 1] = ps[i] + arr[i];
        multiset<long long> st;
        long long res = LLONG_MIN;
        for (int j = a; j <= n; j++) {
            st.insert(ps[j - a]);
            if (j - b - 1 >= 0) st.erase(st.find(ps[j - b - 1]));
            res = max(res, ps[j] - *st.begin());
        }
        return (int)res;
    }
};
