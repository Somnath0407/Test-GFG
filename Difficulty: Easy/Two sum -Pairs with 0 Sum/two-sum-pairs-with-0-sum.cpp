class Solution {
  public:
    vector<vector<int>> getPairs(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        unordered_set<int> s;
        vector<vector<int>> ans;
        for(int i = 0; i < arr.size(); i++) {
            int need = -arr[i];

            if(s.count(need)) {
                ans.push_back({need, arr[i]});
                s.erase(need);   
            }
            else {
                s.insert(arr[i]);
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};