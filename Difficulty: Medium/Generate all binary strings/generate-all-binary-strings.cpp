class Solution {
  public:
    vector<string> binstr(int n) {
        vector<string> res;
        int total = 1 << n;
        for (int i = 0; i < total; i++) {
            string temp = "";
            for (int j = n - 1; j >= 0; j--) {
                if (i & (1 << j)) temp += '1';
                else temp += '0';
            }
            res.push_back(temp);
        }
        return res;
    }
};
