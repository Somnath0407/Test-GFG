// User function Template for C++
class Solution {
  public:
    int findCeil(vector<int>& arr, int x) {
        int low=0,high=arr.size()-1;
        int mid=0,ans=-1;
        while(low<=high){
            mid=low+(high-low)/2;
            if(arr[mid]>=x) {
                ans=mid;
                high=mid-1;
            }
            else if(arr[mid]<x) low=mid+1;
        }
        return ans;
    }
};