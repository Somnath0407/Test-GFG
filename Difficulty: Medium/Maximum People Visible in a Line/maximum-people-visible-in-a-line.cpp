class Solution {
  public:
    int maxPeople(vector<int> &arr) {
        int n = (int)arr.size();
        vector<int> prevGE(n, -1), nextGE(n, n);
        vector<int> st;
        st.reserve(n);

        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.back()] < arr[i]) st.pop_back();
            prevGE[i] = st.empty() ? -1 : st.back();
            st.push_back(i);
        }

        st.clear();

        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && arr[st.back()] < arr[i]) st.pop_back();
            nextGE[i] = st.empty() ? n : st.back();
            st.push_back(i);
        }

        int ans = 1;
        for(int i = 0; i < n; i++){
            int leftVisible = i - prevGE[i] - 1;
            int rightVisible = nextGE[i] - i - 1;
            ans = max(ans, leftVisible + rightVisible + 1);
        }
        return ans;
    }
};
