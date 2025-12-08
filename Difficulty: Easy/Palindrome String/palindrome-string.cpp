class Solution {
public:
    bool isPalindrome(string& s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++; 
            r--;
        }
        return true;
    }
};
