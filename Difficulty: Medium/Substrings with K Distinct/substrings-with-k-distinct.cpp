class Solution {
  public:
    long long atMostK(string &s, int k) {
        if (k < 0) return 0;
        vector<int>v(26, 0);
        int left = 0, distinct = 0;
        long long ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (v[s[i] - 'a']++ == 0)
                distinct++;
            while (distinct > k) {
                if (--v[s[left] - 'a'] == 0)
                    distinct--;
                left++;
            }
            ans += (i - left + 1);
        }
        return ans;
    }
    int countSubstr(string &s, int k) {
        return atMostK(s, k) - atMostK(s, k - 1);
    }
};
