class Solution {

  public:
    long long countTriplets(int n, long long sum, long long arr[]) {
        long long ans=0;
        sort(arr, arr + n);
        for(int i=0;i<n-2;i++){
            int k=n-1;
            for(int j=i+1;j<k;){
                long long target=arr[i]+arr[j]+arr[k];
                if(target<sum){
                    ans+=(k-j);
                    j++;
                }
                else{
                    k--;
                }
            }
        }
        return ans;
    }
};