class Solution {
  public:
   int maxarray(vector<int> &arr,int n){
      int res=arr[0];
      for(int i=1;i<n;i++){
          res=max(res,arr[i]);
      }
      return res;
  }
  int totalarray(vector<int> &arr,int n){
      int sum=0;
      for(int i=0;i<n;i++){
          sum+=arr[i];
      }
      return sum;
  }
  
  bool fun(vector<int> &arr,int n,int mid,int k){
      int student=1;
      int page=0;
      for(int i=0;i<n;i++){
          if(page+arr[i]<=mid){
              page+=arr[i];
          }
          else{
              student++;
              page=arr[i];
              if(student>k) return ;
          }
      }
      return 1;
  }
    int findPages(vector<int> &arr, int k) {
        int n=arr.size();
        if(n<k) return -1;
        int low=maxarray(arr,n),high=totalarray(arr,n);
        int res=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(fun(arr,n,mid,k)){
                res=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return res;
    }
};