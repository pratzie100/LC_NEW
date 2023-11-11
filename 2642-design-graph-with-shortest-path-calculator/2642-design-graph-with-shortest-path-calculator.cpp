class Graph {
public:
    const int INF = 1e9;
    vector<vector<pair<int, int>>> g;
    Graph(int n, vector<vector<int>>& edges) {
        g.resize(n);
        for(int i = 0; i < edges.size(); i++) 
        {
            g[edges[i][0]].push_back(make_pair(edges[i][1], edges[i][2]));
        }
    }
    void addEdge(vector<int> edge) {
        g[edge[0]].push_back(make_pair(edge[1], edge[2]));
    }
    int shortestPath(int node1, int node2) {
        int n=g.size();
        vector<int>dist(n,INF);
        dist[node1]=0;
        priority_queue<pair<int,int>,vector<pair<int, int>>,greater<pair<int,int>>>pq;
        pq.push({0,node1});
        while (!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            for(const auto& edge : g[u]) {
                int v = edge.first;
                int w = edge.second;
                if(dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        return(dist[node2] == INF) ? -1 : dist[node2];
    }
};
