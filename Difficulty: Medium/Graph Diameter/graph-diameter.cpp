class Solution {
  public:
    int bfs(int start, vector<vector<int>>& adj, int& farthest) {
        vector<int> dist(adj.size(), -1);
        queue<int> q;
        q.push(start);
        dist[start] = 0;
        while (!q.empty()) {
            int node = q.front(); q.pop();
            for (int nei : adj[node]) {
                if (dist[nei] == -1) {
                    dist[nei] = dist[node] + 1;
                    q.push(nei);
                }
            }
        }
        int maxDist = 0;
        for (int i = 0; i < adj.size(); i++) {
            if (dist[i] > maxDist) {
                maxDist = dist[i];
                farthest = i;
            }
        }
        return maxDist;
    }
    
    int diameter(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        int farthest = 0;
        bfs(0, adj, farthest);        
        int ans = bfs(farthest, adj, farthest); 
        return ans;
    }
};
