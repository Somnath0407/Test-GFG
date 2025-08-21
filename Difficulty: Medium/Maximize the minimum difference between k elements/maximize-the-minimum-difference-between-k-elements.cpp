class Solution {
  public:
  bool possible(vector<int>& arr, int k, int dist){
      int count = 1;
        int last = arr[0];    
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] - last >= dist) {
                count++;
                last = arr[i];
                if (count == k) return true; 
            }
        }
        return false;
  }
    int maxMinDiff(vector<int>& arr, int k) {
      sort(arr.begin(), arr.end());
      int low =0,high=arr.back()-arr.front(),ans=0;
      while(low<=high){
           int mid=low+(high-low)/2;
          if(possible(arr,k,mid)){
              ans=mid;
              low=mid+1;
          }
          else{
              high=mid-1;
          }
      }
        return ans;
    }
};
