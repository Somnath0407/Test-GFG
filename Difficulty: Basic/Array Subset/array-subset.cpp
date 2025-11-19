class Solution {
public:
    bool isSubset(vector<int> &a, vector<int> &b) {
        unordered_map<int,int> mp;
        for(int x : a) mp[x]++;
        for(int x : b){
            if(mp[x] == 0) return false;
            mp[x]--;
        }
        return true;
    }
};
