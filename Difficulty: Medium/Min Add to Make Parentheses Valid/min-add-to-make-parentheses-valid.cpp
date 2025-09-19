class Solution {
public:
    int minParentheses(string& s) {
        int count = 0, back = 0;
        for (char c : s) {
            if (c == '(') count++;
            else if (c == ')') {
                if (count > 0) count--;
                else back++;
            }
        }
        return count + back;
    }
};
