class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        for(int i=0;i<arr.size();i++){
            if(arr[i]<=k){
                k++;
            }
            else{
                return k;
            }
        }
        return k;
    }
};