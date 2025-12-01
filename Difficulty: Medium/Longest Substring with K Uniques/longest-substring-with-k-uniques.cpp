class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        int n = s.size();
        vector<int> freq(26, 0);
        int distinct = 0, ans = -1;
        int l = 0;
        for (int r = 0; r < n; ++r) {
            int cr = s[r] - 'a';
            if (freq[cr] == 0) distinct++;
            freq[cr]++;
            while (distinct > k) {
                int cl = s[l] - 'a';
                freq[cl]--;
                if (freq[cl] == 0) distinct--;
                l++;
            }
            if (distinct == k) {
                ans = max(ans, r - l + 1);
            }
        }
        return ans;
    }
};
