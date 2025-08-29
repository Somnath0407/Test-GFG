class Solution {
  public:
    string smallestWindow(string s, string p) {
        if (s.size() < p.size()) return "";
        
        vector<int> freqP(26, 0), freqS(26, 0);
        for (char c : p) freqP[c - 'a']++;
        
        int count = 0, start = 0, minLen = INT_MAX, startIndex = -1;
        
        for (int end = 0; end < s.size(); end++) {
            freqS[s[end] - 'a']++;
            
            if (freqS[s[end] - 'a'] <= freqP[s[end] - 'a'])
                count++;
            
            while (count == p.size()) {
                if (end - start + 1 < minLen) {
                    minLen = end - start + 1;
                    startIndex = start;
                }
                
                freqS[s[start] - 'a']--;
                if (freqS[s[start] - 'a'] < freqP[s[start] - 'a'])
                    count--;
                start++;
            }
        }
        
        if (startIndex == -1) return "";
        return s.substr(startIndex, minLen);
    }
};