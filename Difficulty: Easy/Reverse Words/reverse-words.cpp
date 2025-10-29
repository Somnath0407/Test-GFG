class Solution {
  public:
    string reverseWords(string &s) {
        vector<string> words;
        string temp = "";
        for (char c : s) {
            if (c == '.') {
                if (!temp.empty()) {
                    words.push_back(temp);
                    temp.clear();
                }
            } else temp += c;
        }
        if (!temp.empty())
        words.push_back(temp);
        
        reverse(words.begin(), words.end());
        
        string res = "";
        for (int i = 0; i < words.size(); i++) {
            res += words[i];
            if (i < words.size() - 1) 
            res += '.';
        }
        return res;
    }
};
