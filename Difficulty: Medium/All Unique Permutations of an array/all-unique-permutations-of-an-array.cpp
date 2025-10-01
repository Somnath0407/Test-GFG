class Solution {
  public:
    vector<vector<int>> uniquePerms(vector<int>& arr) {
       set<vector<int>>s;
       sort(arr.begin(),arr.end());
       do{
           s.insert(arr);
       } while(next_permutation(arr.begin(), arr.end()));
       
       
        return vector<vector<int>>(s.begin(),s.end());
    }
};