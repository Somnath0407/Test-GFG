class Solution {
  public:
  void get(int idx,vector<int>&arr,vector<vector<int>>&ans){
      int n=arr.size();
      if(idx==n){
          ans.push_back(arr);
          return ;
      }
      for(int i=idx;i<n;i++){
          swap(arr[idx],arr[i]);
          get(idx+1,arr,ans);
          swap(arr[idx],arr[i]);
      }
  }
    vector<vector<int>> permuteDist(vector<int>& arr) {
        vector<vector<int>>ans;
        get(0,arr,ans);
        return ans;
    }
};