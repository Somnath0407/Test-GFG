class Solution {
  public:
    string largestSwap(string &s) {
        int n = s.size();
        for (int i = 0; i < n; i++) {
            char best = s[i];
            int pos = i;
            for (int j = i+1; j < n; j++) {
                if (s[j] >= best) { 
                    best = s[j];
                    pos = j;
                }
            }
            if (best > s[i]) {
                swap(s[i], s[pos]);
                return s;
            }
        }
        return s; 
    }
};
