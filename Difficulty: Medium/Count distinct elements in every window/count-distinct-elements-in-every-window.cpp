class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        int n=arr.size();
        vector<int>v;
        unordered_map<int,int>m;
        int sum=0;
        for(int i = 0; i < k; i++){
            m[arr[i]]++;
        }
        v.push_back(m.size());
        for(int i=k;i<n;i++){
            if(--m[arr[i-k]]==0){
                m.erase(arr[i-k]);
            }
            m[arr[i]]++;
            v.push_back(m.size());
        }
        return v;
    }
};