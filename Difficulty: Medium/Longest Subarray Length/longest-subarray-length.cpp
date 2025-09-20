class Solution {
public:
    int longestSubarray(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> buckets(n+1);
        for (int i = 0; i < n; ++i)
            if (arr[i] <= n) buckets[arr[i]].push_back(i);

        vector<int> parent(n), sz(n,1);
        vector<char> active(n, 0);
        iota(parent.begin(), parent.end(), 0);

        function<int(int)> findp = [&](int x){
            while (parent[x] != x) {
                parent[x] = parent[parent[x]];
                x = parent[x];
            }
            return x;
        };
        auto unite = [&](int a, int b){
            a = findp(a); b = findp(b);
            if (a == b) return;
            if (sz[a] < sz[b]) swap(a,b);
            parent[b] = a;
            sz[a] += sz[b];
        };

        int ans = 0, maxSeg = 0;
        for (int v = 1; v <= n; ++v) {
            for (int idx : buckets[v]) {
                active[idx] = 1;
                if (idx-1 >= 0 && active[idx-1]) unite(idx, idx-1);
                if (idx+1 < n && active[idx+1]) unite(idx, idx+1);
                int root = findp(idx);
                maxSeg = max(maxSeg, sz[root]);
            }
            if (maxSeg >= v) ans = v;
        }
        return ans;
    }
};
