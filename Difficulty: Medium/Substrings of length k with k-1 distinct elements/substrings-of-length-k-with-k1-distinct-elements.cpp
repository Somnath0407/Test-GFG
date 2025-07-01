class Solution {
  public:
    int substrCount(string &s, int k) {
        if (k > s.size()) return 0;

        int count = 0;
        int freq[26] = {0};
        int distinct = 0;

        // First window
        for (int i = 0; i < k; ++i) {
            if (freq[s[i] - 'a'] == 0) distinct++;
            freq[s[i] - 'a']++;
        }
        if (distinct == k - 1) count++;

        // Slide the window
        for (int i = k; i < s.size(); ++i) {
            char out = s[i - k];
            freq[out - 'a']--;
            if (freq[out - 'a'] == 0) distinct--;

            char in = s[i];
            if (freq[in - 'a'] == 0) distinct++;
            freq[in - 'a']++;

            if (distinct == k - 1) count++;
        }

        return count;
    }
};
