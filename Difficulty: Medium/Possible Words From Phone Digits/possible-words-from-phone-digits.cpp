class Solution {
  public:
  void solve(int index,vector<int> &arr,vector<string>& map,string temp,vector<string>&ans){
        if(index== arr.size()){
           ans.push_back(temp);
            return;
        }
        int number =arr[index];
        if (map[number].empty()) {
            solve(index + 1, arr, map, temp, ans);
            return;
        }
        for(char ch:map[number]){
            temp.push_back(ch);
            solve(index+1,arr,map,temp,ans);
            temp.pop_back();
        }
        
  }
    vector<string> possibleWords(vector<int> &arr) {
        vector<string> map = {
            "",    
            "",    
            "abc", 
            "def", 
            "ghi", 
            "jkl", 
            "mno", 
            "pqrs",
            "tuv", 
            "wxyz" 
        };
        string temp = "";
        vector<string>ans;
        solve(0,arr,map,temp,ans);
        return ans;
    }
};