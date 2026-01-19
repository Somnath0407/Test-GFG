class Solution {
  public:
    string removeKdig(string &s, int k) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            while(!st.empty() && k>0 && ((st.top() - '0')>(s[i] -'0'))){
                st.pop();
                k--;
            }
            st.push(s[i]);
        }
        while(k>0){
            st.pop();
            k--;
        }
        if(st.empty()) return "0";
        string m="";
        while(!st.empty()){
            m.push_back(st.top());
            st.pop();
        }
        while(m.size()!=0 && m.back()=='0'){
            m.pop_back();
        }
        reverse(m.begin(), m.end());
        if(m.empty()){
            return "0";
        }
        return m;
    }
};