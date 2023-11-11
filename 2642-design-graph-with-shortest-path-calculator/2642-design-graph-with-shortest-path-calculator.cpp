class Graph {
public:
    const int INF = 1e9;
    vector<vector<pair<int, int>>> g;
    Graph(int n, vector<vector<int>>& edges) {
        // Resize the adjacency list to accommodate 'n' nodes
        g.resize(n);
        for (int i = 0; i < edges.size(); i++) {
            g[edges[i][0]].push_back(make_pair(edges[i][1], edges[i][2]));
        }
    }
    // Function to add an edge to the graph
    void addEdge(vector<int> edge) {
        g[edge[0]].push_back(make_pair(edge[1], edge[2]));
    }

    // Function to find the shortest path from node1 to node2
    int shortestPath(int node1, int node2) {
        // Get the number of nodes in the graph
        int n = g.size();

        // Initialize a vector to store the minimum distances from node1 to other nodes
        vector<int> dist(n, INF);

        // The distance from node1 to itself is 0
        dist[node1] = 0;

        // Priority queue to store pairs of (distance, node) in ascending order of distance
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // Add the starting node and its distance (0) to the priority queue
        pq.push({0, node1});

        // Dijkstra's algorithm main loop
        while (!pq.empty()) {
            // Get the node with the currently smallest known distance
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            // Iterate through all neighbors of the current node
            for (const auto& edge : g[u]) {
                int v = edge.first;  // Neighbor node
                int w = edge.second; // Weight of the edge

        // Relaxation step: Update the distance to the neighbor if a shorter path is found
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    // Add the updated distance and the neighbor to the priority queue
                    pq.push({dist[v], v});
                }
            }
        }
        // Return the shortest path from node1 to node2
        // If there is no path, return -1
        return (dist[node2] == INF) ? -1 : dist[node2];
    }
};
