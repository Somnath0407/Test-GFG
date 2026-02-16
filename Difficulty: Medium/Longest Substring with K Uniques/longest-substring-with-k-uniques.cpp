class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        unordered_map<int,int>m;
        int low=0,res=-1;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
            while(m.size()>k){
                m[s[low]]--;
                if(m[s[low]]==0) m.erase(s[low]);
                low++;
            }
            if(m.size()==k){
                res=max(res,i-low+1);
            }
        }
        return res;
    }
};