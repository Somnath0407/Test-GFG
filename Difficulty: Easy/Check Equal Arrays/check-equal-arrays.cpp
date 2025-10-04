class Solution {
  public:
    bool checkEqual(vector<int>& a, vector<int>& b) {
        if (a.size() != b.size()) return false;
        unordered_map<long long, int> freq;
        for (int i = 0; i < a.size(); i++) {
            freq[a[i]]++;
        }
        for (int i = 0; i < b.size(); i++) {
            if (freq.find(b[i]) == freq.end() || freq[b[i]] == 0)
                return false;
            freq[b[i]]--;
        }
        return true;
    
        
    }
};