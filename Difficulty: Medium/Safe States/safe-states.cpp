class Solution {
  public:
    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        vector<vector<int>> rev(V);
        vector<int> indeg(V, 0);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            rev[v].push_back(u);
            indeg[u]++;
        }
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indeg[i] == 0)
                q.push(i);
        }
        vector<int> ans;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for (int j = 0; j < rev[node].size(); j++) {
                int next = rev[node][j];
                indeg[next]--;
                if (indeg[next] == 0)
                    q.push(next);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
