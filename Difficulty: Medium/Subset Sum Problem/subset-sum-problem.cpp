class Solution {
  public:
  bool fun(vector<int>& arr, int sum,int n,int i,vector<vector<int>>&dp){
      if(sum==0) return true;
      if(i==n) return false;
      if(dp[i][sum]!=-1) return dp[i][sum];
      if(arr[i]>sum) return dp[i][sum]=fun(arr,sum,n,i+1,dp);
      bool pick=fun(arr,sum-arr[i],n,i+1,dp);
      bool nonpick=fun(arr,sum,n,i+1,dp);
      return dp[i][sum]=pick || nonpick;
  }
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return fun(arr,sum,n,0,dp);
    }
};