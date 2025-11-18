class Solution {
public:
    int countPaths(int V, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(V);
        for(auto &e : edges){
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
        
        const long long INF = 1e18;
        vector<long long> dist(V, INF);
        vector<long long> ways(V, 0);
        
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});
        
        while(!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();
            
            if(d > dist[node]) continue;
            
            for(auto &p : adj[node]) {
                int next = p.first;
                long long wt = p.second;
                long long newDist = d + wt;
                
                if(newDist < dist[next]) {
                    dist[next] = newDist;
                    ways[next] = ways[node];
                    pq.push({newDist, next});
                }
                else if(newDist == dist[next]) {
                    ways[next] += ways[node];
                }
            }
        }
        
        return ways[V-1];
    }
};
