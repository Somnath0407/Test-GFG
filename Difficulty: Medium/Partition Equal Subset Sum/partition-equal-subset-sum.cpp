class Solution {
  public:
    bool fun(vector<int>& arr,int sum,vector<vector<int>>&dp,int n,int i){
        if(sum==0) return true;
        if(i==n) return false;
        if(dp[i][sum]!=-1) return dp[i][sum];
        if(arr[i]>sum) return dp[i][sum]= fun(arr,sum,dp,n,i+1);
        int pick=fun(arr,sum-arr[i],dp,n,i+1);
        int unpick=fun(arr,sum,dp,n,i+1);
        return dp[i][sum]=pick||unpick;
    }
    bool equalPartition(vector<int>& arr) {
        // code here
        int n=arr.size();
        int totalsum=0;
        for(int i=0;i<n;i++){
            totalsum+=arr[i];
        }
        if(totalsum%2!=0) return false;
        int sum=totalsum/2;
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return fun(arr,sum,dp,n,0);
    }
};