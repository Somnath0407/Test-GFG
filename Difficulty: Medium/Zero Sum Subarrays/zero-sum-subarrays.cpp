class Solution {
  public:
    int findSubarray(vector<int> &arr) {
        int total=0;
        unordered_map<int,int>m;
        int prefixsum=0;
        m[0]=1;
        for(int i=0;i<arr.size();i++){
            prefixsum+=arr[i];
            if(m.count(prefixsum)){
                total+=m[prefixsum];
                m[prefixsum]++;
            }
            else{
                m[prefixsum]=1;
            }
        }
        return total;
    }
};