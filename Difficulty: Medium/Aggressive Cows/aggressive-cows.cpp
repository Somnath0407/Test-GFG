class Solution {
  public:
    int helper(vector<int> &stalls,int mid,int n){
        int cow=1;
        int last=stalls[0];
        for(int i=1;i<n;i++){
            if(abs(stalls[i]-last)>=mid){
                cow++;
                last=stalls[i];
            }
        }
        return cow;
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        int n=stalls.size();
        sort(stalls.begin(),stalls.end());
        int low=0,high=stalls[n-1]-stalls[0];
        int res=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            int cow=helper(stalls,mid,n);
            if(cow<k){
                high=mid-1;
            }
            else{
                res=mid;
                low=mid+1;
            }
        }
        return res;
    }
};