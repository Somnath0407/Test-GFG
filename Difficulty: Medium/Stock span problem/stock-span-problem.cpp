class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        int n=arr.size();
        vector<int>ans(n);
        stack<pair<int,int>>p;
        for(int i=0;i<n;i++){
            while(!p.empty() && arr[i]>=p.top().first){
                p.pop();
            }
            ans[i]=i-(p.empty() ? -1 : p.top().second);
            p.push({arr[i],i});
        }
        return ans;
    }
};