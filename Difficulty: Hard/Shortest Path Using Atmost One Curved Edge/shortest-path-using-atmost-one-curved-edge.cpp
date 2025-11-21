class Solution {
public:
    int shortestPath(int V, int a, int b, vector<vector<int>> &edges) {
        vector<vector<pair<int,int>>> g(V);
        for(auto &e: edges){
            g[e[0]].push_back({e[1], e[2]});
            g[e[1]].push_back({e[0], e[2]});
        }

        auto dijkstra = [&](int src){
            const int INF = 1e18;
            vector<long long> dist(V, INF);
            priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
            dist[src] = 0;
            pq.push({0, src});
            while(!pq.empty()){
                auto [d, u] = pq.top(); pq.pop();
                if(d > dist[u]) continue;
                for(auto &p: g[u]){
                    int v = p.first, w = p.second;
                    if(dist[v] > d + w){
                        dist[v] = d + w;
                        pq.push({dist[v], v});
                    }
                }
            }
            return dist;
        };

        auto distA = dijkstra(a);
        auto distB = dijkstra(b);

        long long ans = distA[b];
        const long long INF = 1e18;

        for(auto &e: edges){
            int x=e[0], y=e[1], w2=e[3];
            if(distA[x] < INF && distB[y] < INF)
                ans = min(ans, distA[x] + w2 + distB[y]);
            if(distA[y] < INF && distB[x] < INF)
                ans = min(ans, distA[y] + w2 + distB[x]);
        }

        return ans >= INF ? -1 : ans;
    }
};
