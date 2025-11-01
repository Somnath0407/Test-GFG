class Solution {
  public:
    vector<int> findOrder(int n, vector<vector<int>> &prerequisites) {
        vector<vector<int>> g(n);
        vector<int> indeg(n, 0), res;
        for (int i = 0; i < prerequisites.size(); i++) {
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
            g[b].push_back(a);
            indeg[a]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0)
                q.push(i);
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            res.push_back(u);
            for (int j = 0; j < g[u].size(); j++) {
                int v = g[u][j];
                indeg[v]--;
                if (indeg[v] == 0)
                    q.push(v);
            }
        }
        if (res.size() == n)
            return res;
        return {};
    }
};
