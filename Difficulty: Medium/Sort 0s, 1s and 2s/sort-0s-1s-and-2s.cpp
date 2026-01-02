class Solution {
  public:
    void sort012(vector<int>& arr) {
        int l=0,m=0,r=arr.size()-1;
        while(m<=r){
            if(arr[m]==0) 
                swap(arr[l++],arr[m++]);
            else if(arr[m]==1) 
                m++;
            else 
                swap(arr[m],arr[r--]);
        }
    }
};