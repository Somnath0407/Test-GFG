class Solution {
  public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        if(n<=1) return 0;
        if(arr[0]==0) return -1;
        int maxfind=arr[0], ans=1, curEnd=arr[0];
        for(int i=1;i<n;i++){
            if(i==n-1) return ans;
            maxfind=max(maxfind,i+arr[i]);
            if(i==curEnd){
                ans++;
                if(i>=maxfind) return -1;
                curEnd=maxfind;
            }
        }
        return -1;
    }
};
