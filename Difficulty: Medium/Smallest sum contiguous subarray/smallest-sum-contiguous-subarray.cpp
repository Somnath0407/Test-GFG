// User function Template for C++

class Solution {
  public:
    int smallestSumSubarray(vector<int>& a) {
        int badending=a[0],ans=a[0];
        for(int i=1;i<a.size();i++){
            int v1=badending+a[i];
            int v2=a[i];
            badending=min(v1,v2);
            ans=min(ans,badending);
        }
        return ans;
    }
};
