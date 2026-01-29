class Solution {
public:
    using ll = long long;
    const ll INF = 1e18;

    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n);

        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});       
            adj[v].push_back({u, 2 * w});   
        }

        vector<ll> dist(n, INF);
        priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;

        dist[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [cost, node] = pq.top();
            pq.pop();

            if (cost > dist[node]) continue;

            for (auto [next, w] : adj[node]) {
                if (cost + w < dist[next]) {
                    dist[next] = cost + w;
                    pq.push({dist[next], next});
                }
            }
        }

        return dist[n - 1] == INF ? -1 : dist[n - 1];
    }
};