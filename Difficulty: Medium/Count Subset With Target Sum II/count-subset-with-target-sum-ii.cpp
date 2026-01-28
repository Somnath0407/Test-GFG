class Solution {
  public:
    int countSubset(vector<int> &arr, int k) {
        int n=arr.size();
        int mid=n/2;
        vector<int>left(arr.begin(),arr.begin()+mid);
        vector<int>right(arr.begin()+mid,arr.end());
        unordered_map<int,int>m;
        for(int i=0;i<(1<<right.size());i++){
            int sum=0;
            for(int j=0;j<right.size();j++){
                if(i&(1<<j)){
                    sum+=right[j];
                }
            }
           m[sum]++; 
        }
        int ans=0;
        for(int i=0;i<(1<<left.size());i++){
            int sum=0;
            for(int j=0;j<left.size();j++){
                if(i&(1<<j)){
                    sum+=left[j];
                }
            }
            ans+=m[k-sum];
        }
        return ans;
    }
};