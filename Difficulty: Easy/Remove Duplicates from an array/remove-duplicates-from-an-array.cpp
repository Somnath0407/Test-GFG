class Solution {
public:
    vector<int> remDuplicate(vector<int>& arr) {
        set<int> s(arr.begin(), arr.end());
        return vector<int>(s.begin(), s.end());
    }
};
