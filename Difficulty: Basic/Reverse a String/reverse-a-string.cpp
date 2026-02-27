// User function Template for C++
class Solution {
  public:
    string revStr(string s) {
        stack<char>k;
        string ans="";
        for(int i=0;i<s.size();i++){
            k.push(s[i]);
        }
        while(!k.empty()){
            ans+=k.top();
            k.pop();
        }
        return ans;
    }
};