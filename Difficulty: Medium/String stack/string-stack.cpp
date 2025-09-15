

class Solution {
  public:
    bool stringStack(string &pat, string &tar) {
        int i = pat.size() - 1;
        int j = tar.size() - 1;
        while (i >= 0 && j >= 0) {
            if (pat[i] == tar[j]) {
                i--;
                j--;
            } else {
                i -= 2; 
            }
        }
        return j < 0;
    }
};
