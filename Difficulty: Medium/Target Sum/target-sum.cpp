class Solution {
  public:
  int fun(vector<int>& arr,int sum,vector<vector<int>>&dp,int n,int i){
      if(sum==0) return 1;
      if(i==n) return 0;
      if(dp[i][sum]!=-1) return dp[i][sum];
      if(arr[i]>sum) return dp[i][sum]=fun(arr,sum,dp,n,i+1);
      int pick =fun(arr,sum-arr[i],dp,n,i+1);
      int nonpick=fun(arr,sum,dp,n,i+1);
      return dp[i][sum]=pick+nonpick;
  }
    int totalWays(vector<int>& arr, int target) {
        //  code here
        int n=arr.size();
        int totalsum=0;
        int sum=0;
        for(int i=0;i<n;i++){
            totalsum+=arr[i];
        }
        if(abs(totalsum)<target) return 0;
        if ((totalsum + target) % 2 != 0) return 0;
        sum=(totalsum+target)/2;
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return fun(arr,sum,dp,n,0);
    }
};