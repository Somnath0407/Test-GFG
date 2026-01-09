class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        unordered_map<int,int> m;
        int j=0,ans=0;
        for(int i=0;i<arr.size();i++){
            m[arr[i]]++;
            while(m.size()>k){
                m[arr[j]]--;
                if(m[arr[j]] == 0) m.erase(arr[j]);
                j++;
            }
            ans+=(i-j+1);
        }
        return ans;
    }
};