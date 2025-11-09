class Solution {
  public:
    string reverseWords(string &s) {
        reverse(s.begin(), s.end());
        int n = s.size();
        int start = 0;
        string res = "";
        for (int i = 0; i <= n; ++i) {
            if (i == n || s[i] == '.') {
                int len = i - start;
                if (len > 0) {                 
                    reverse(s.begin() + start, s.begin() + i); 
                    if (!res.empty()) res.push_back('.');
                    res.append(s.substr(start, len));
                }
                start = i + 1;
            }
        }
        return res;
    }
};
