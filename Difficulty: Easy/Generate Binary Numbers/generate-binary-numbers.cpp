class Solution {
  public:
    vector<string> generateBinary(int n) {
       vector<string> ans;
        for(int i = 1; i <= n; i++) {
            string s = bitset<32>(i).to_string();  
            ans.push_back(s.substr(s.find('1')));  
        }
        return ans; 
    }
};