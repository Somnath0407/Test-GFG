class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        int n = arr.size();
        int left = 0, zeroCount = 0, maxLen = 0;
        for(int i=0;i<n;i++){
            if(arr[i]==0) zeroCount++;
            
            while(zeroCount>k){
                if(arr[left]==0) zeroCount--;
                left++;
            }
             maxLen = max(maxLen, i - left + 1);
        }
        return maxLen;
    }
};
