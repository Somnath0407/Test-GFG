class Solution {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        int n=arr.size();
        if(k > n) return 0;
        int maxxor=0,total = INT_MIN;
        for(int i=0;i<k;i++){
            maxxor=arr[i]  ^ maxxor;
        }
        total=maxxor;
        for(int i=k;i<n;i++){
            maxxor ^= arr[i - k]; 
            maxxor ^=arr[i];
            total = max(total, maxxor);
        }
        return total;
        
    }
};