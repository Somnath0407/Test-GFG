class Solution {
  public:
  int firstpos(vector<int>& arr,int x){
      int low=0,high=arr.size()-1;
      int ans=-1;
      while(low<=high){
          int mid=low+(high-low)/2;
          if(arr[mid]==x){
              ans=mid;
              high=mid-1;
          }
          else if(arr[mid]<x){
              low=mid+1;
          }
          else{
              high=mid-1;
          }
      }
      return ans;
  }
  int lastpos(vector<int>& arr,int x){
      int low=0,high=arr.size()-1;
      int ans=-1;
      while(low<=high){
          int mid=low+(high-low)/2;
          if(arr[mid]==x){
              ans=mid;
              low=mid+1;
          }
          else if(arr[mid]<x){
              low=mid+1;
          }
          else{
              high=mid-1;
          }
      }
      return ans;
  }
    vector<int> countXInRange(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;
        int n = arr.size();
        for(int i=0;i<queries.size();i++){
            int l=queries[i][0];
            int r=queries[i][1];
            int x=queries[i][2];
            int first=firstpos(arr,x);
            int last=lastpos(arr,x);
            if(first==-1 || last==-1){
                ans.push_back(0);
                continue;
            }
            else{
                int start=max(first,l);
                int end=min(last,r);
                if(start>end){
                    ans.push_back(0);
                }
                else{
                    ans.push_back(end-start+1);
                }
            }
        }
        return ans;
    }
};