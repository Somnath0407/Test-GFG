class Solution {
  public:
    vector<int> nextGreater(vector<int> &arr) {
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> st;  
        for (int i = 2 * n - 1; i >= 0; i--) {
            int s = i % n;
            while (!st.empty() && arr[st.top()] <= arr[s]) {
                st.pop();
            }
            if (i < n && !st.empty()) {
                ans[s] = arr[st.top()];
            }
            st.push(s);
        }
        return ans;
    }
};
