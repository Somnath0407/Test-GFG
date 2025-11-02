class Solution {
  public:
    int maxEdgesToAdd(int V, vector<vector<int>>& edges) {
        unordered_set<long long> seen;
        seen.reserve(edges.size()*2 + 10);
        const long long B = 1000000LL;
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            if (u == v)
            continue;
            seen.insert(u * B + v);
        }
        long long uniqueE = (long long)seen.size();
        long long maxPossible = (long long)V * (V - 1) / 2LL;
        long long ans = maxPossible - uniqueE;
        if (ans < 0)
        ans = 0; 
        return (int)ans;
    }
};
