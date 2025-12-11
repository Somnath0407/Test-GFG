class Solution {
  public:
    int isValid(string &s) {
        vector<string> parts; string cur;
        for(char c: s) {
            if(c=='.') { parts.push_back(cur); cur.clear(); }
            else cur.push_back(c);
        }
        parts.push_back(cur);
        if(parts.size() != 4) return 0;
        for(const string &p: parts) {
            if(p.empty() || p.size() > 3) return 0;
            if(p.size() > 1 && p[0] == '0') return 0;
            int val = 0;
            for(char ch: p) {
                if(!isdigit(ch)) return 0;
                val = val*10 + (ch - '0');
                if(val > 255) return 0;
            }
        }
        return 1;
    }
};
