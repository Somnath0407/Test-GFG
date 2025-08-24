class Solution {
  public:
    int minDaysBloom(vector<int>& arr, int k, int m) {
        sort(arr.begin(),arr.end());
        long long totalflower=m*k;
        if(totalflower>arr.size()){
            return -1;
        }
        for(int i=0;i<arr.size();i++){
            if(i==(totalflower-1)){
                return arr[i];
            }
        }
    }
};