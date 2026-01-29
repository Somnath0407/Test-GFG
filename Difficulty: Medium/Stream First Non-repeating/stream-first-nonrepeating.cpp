class Solution {
  public:
    string firstNonRepeating(string &s) {
        vector<int>v(26,0);
        queue<char>q;
        string ans="";
        for(int i =0;i<s.length();i++){
            v[s[i]-'a']++;
            q.push(s[i]);
            while(!q.empty() && v[q.front()-'a']>1){
                q.pop();
            }
            if(q.empty()){
                ans+='#';
            }
            else{
                ans+=q.front();
            }
        }
        return ans;
    }
};