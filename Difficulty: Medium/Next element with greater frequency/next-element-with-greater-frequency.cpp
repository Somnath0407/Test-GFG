class Solution {
  public:
    vector<int> nextFreqGreater(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> freq;

        for(int i = 0; i < n; i++){
            freq[arr[i]]++;
        }

        vector<int> ans(n, -1);
        vector<int> st;

        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && freq[st.back()] <= freq[arr[i]]){
                st.pop_back();
            }
            if(!st.empty()) ans[i] = st.back();
            st.push_back(arr[i]);
        }

        return ans;
    }
};
