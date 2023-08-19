class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        // Create an adjacency list to represent the graph
        vector<vector<pair<int,int>>> g(n);
        // Populate the adjacency list with edges and their weight
        for(auto &e:edges) 
        {
            int u=e[0],v=e[1],w=e[2];
            g[u].push_back(make_pair(v,w));
            g[v].push_back(make_pair(u,w));
        }
        // Initialize result vectors for critical and pseudo-critical edges
        vector<vector<int>>ans(2);
        // Iterate through all edges in the input
        for (int i=0; i<edges.size(); i++) 
        {
            auto &e = edges[i];
            int u=e[0], v=e[1], w=e[2];
            // Calculate the minimax value when excluding the current edge
            int m = minimax(g, u, v);
            // Check if the current edge is critical or pseudo-critical
            if(w < m) ans[0].push_back(i);  // Critical edge
            else if(w == m) ans[1].push_back(i);// Pseudo-critical edge
        }
        return ans;
    }
    
     // Function calculateS minimax value using modified Dijkstra's algorithm
    int minimax(vector<vector<pair<int,int>>> &g, int src, int dst) {
        vector<int> dist(g.size(),1e9);// Initialize distances to a large value
        priority_queue<pair<int,int>> pq; // Priority queue for vertex processing
        dist[src]=0;
        pq.push(make_pair(0,src)); // Push source vertex with distance 0 into the queue
        
        while (!pq.empty()) 
        {
            int pri = pq.top().first; // Current priority (negative distance)
            int u = pq.top().second;// Current vertex
            pq.pop(); // Remove the current vertex from the queue
            
            // Ignore this vertex if its priority is higher than the stored distance
            if(pri>dist[u]) continue;
              
            // Process neighbors of the current vertex
            for(auto neighbor : g[u]) 
            {
                int v = neighbor.first;// Neighbor vertex
                int w = neighbor.second;// Edge weight
                if(u == src && v == dst) continue; // Skip the edge (u, v) if it's the same as (src, dst)

                 // Update distance if a shorter path is found
                if(dist[v] > max(dist[u],w))
                {
                    dist[v] = max(dist[u], w);
                    pq.push(make_pair(dist[v], v));
                }
            }
        }
        return dist[dst]; // Return the minimax distance to the destination vertex
    }
    
};
