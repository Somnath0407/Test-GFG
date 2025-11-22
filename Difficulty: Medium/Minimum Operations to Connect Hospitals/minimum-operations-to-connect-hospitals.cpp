class Solution {
public:
    void dfs(int node, vector<int> &vis, vector<vector<int>> &adj){
        vis[node] = 1;
        for(int nxt : adj[node]){
            if(!vis[nxt]) dfs(nxt, vis, adj);
        }
    }
    
    int minConnect(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> vis(V, 0);
        int components = 0;
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                components++;
                dfs(i, vis, adj);
            }
        }
        
        int E = edges.size();
        int extra = E - (V - components);
        
        int required = components - 1;
        
        if(extra >= required) return required;
        return -1;
    }
};
