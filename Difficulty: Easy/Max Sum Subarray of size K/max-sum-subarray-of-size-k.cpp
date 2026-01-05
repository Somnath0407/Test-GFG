class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        int n = arr.size();
        if(n < k) return 0;
        int sum = 0, total = INT_MIN;
        for(int i = 0; i < k; i++){
            sum += arr[i];
        }
        total=sum;
        for(int i=k;i<n;i++){
            sum+=arr[i]-arr[i-k];
            total = max(total, sum);
        }
        return total;
    }
};