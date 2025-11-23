class Solution {
public:
    int maxRemove(vector<vector<int>>& stones) {
        int n = stones.size();
        unordered_map<int,int> parent;

        function<int(int)> find = [&](int x){
            if(parent[x] == x) return x;
            return parent[x] = find(parent[x]);
        };

        auto unite = [&](int x, int y){
            x = find(x);
            y = find(y);
            if(x != y) parent[y] = x;
        };

        for(auto &s : stones){
            int r = s[0];
            int c = s[1] + 10001;  
            if(!parent.count(r)) parent[r] = r;
            if(!parent.count(c)) parent[c] = c;
            unite(r,c);
        }
        unordered_set<int> comps;
        for(auto &s : parent) comps.insert(find(s.first));

        return n - comps.size();
    }
};
