class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        int low=0,high=arr.size()-1;
        int ans=INT_MAX;
        int idx=0;
        while(low<=high){
            int mid=low+(high-low)/2;
           if(arr[mid]>arr[high]){
            low=mid+1;
           }
           else{
                if(arr[mid]<ans){
                    ans=arr[mid];
                    idx=mid;
                }
                high=mid-1;
           } 
        }
        return idx;
    }
};
