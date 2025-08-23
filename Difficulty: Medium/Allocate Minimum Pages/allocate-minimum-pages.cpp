class Solution {
  public:
    int findPages(vector<int> &arr, int k) {
        int n=arr.size();
        if(k>n) return -1;
        
        int low = arr[0], high = 0;
        for (int i = 0; i < n; i++) {
            low = max(low, arr[i]);  
            high += arr[i];          
        }

        int ans = -1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int count=1,page=0;
            for(int i=0;i<n;i++){
                if(page+arr[i]>mid){
                    count++;
                    page=arr[i];
                }
                else{
                    page+=arr[i];
                }
            }
            if(count<=k){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};