class Solution {
  public:
    void sort012(vector<int>& arr) {
        int l=0,m=0,n=arr.size()-1;
        while(m<=n){
            if(arr[m]==0){
                swap(arr[l++],arr[m++]);
            }
            else if(arr[m]==1){
                arr[m++];
            }
            else{
                swap(arr[m],arr[n--]);
            }
        }
    }
};