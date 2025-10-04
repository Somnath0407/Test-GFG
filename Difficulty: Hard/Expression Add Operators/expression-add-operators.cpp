class Solution {
  public:
    vector<string> findExpr(string s, int target) {
        vector<string> res;
        dfs(s, target, 0, 0, 0, "", res);
        sort(res.begin(), res.end()); 
        return res;
    }

  private:
    void dfs(string &s, long long target, int pos, long long eval, long long multed,
             string path, vector<string>& res) {
        if (pos == s.size()) {
            if (eval == target) res.push_back(path);
            return;
        }

        for (int i = pos; i < s.size(); i++) {
            if (i != pos && s[pos] == '0') break; 
            string curStr = s.substr(pos, i - pos + 1);
            long long cur = stoll(curStr);

            if (pos == 0) {
                dfs(s, target, i + 1, cur, cur, curStr, res);
            } else {
                dfs(s, target, i + 1, eval + cur, cur, path + "+" + curStr, res);
                dfs(s, target, i + 1, eval - cur, -cur, path + "-" + curStr, res);
                dfs(s, target, i + 1, eval - multed + multed * cur, multed * cur,
                    path + "*" + curStr, res);
            }
        }
    }
};
