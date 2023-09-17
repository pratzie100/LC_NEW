class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        // Initialize a bitmask to represent visited nodes.
        // In the bitmask, each bit position corresponds to a node.
        // If a bit is set to 1, it means the corresponding node has been visited.
        int mask = (1 << n) - 1; // For n nodes, there are 2^n possible bit combinations.
        queue<pair<int, pair<int, int>>> q; // Queue to perform BFS.
        // 2D array to keep track of visited nodes using bit manipulation.
        // visited[mask][node] is true if the node has been visited with the given bitmask.
        vector<vector<bool>> visited(mask + 1, vector<bool>(n, false));
        // Initialize the queue with starting nodes and mark them as visited.
        for (int node = 0; node < n; node++) 
        {
            int origMask = (1 << node); // Create a bitmask for the initial node   
            // Push the node into the queue along with bitmask and length.
            q.push({node, {origMask, 1}});
            // Mark the node as visited in the bitmask.
            visited[origMask][node] = true;
        }
        while (!q.empty()) 
        {
            auto curr = q.front();
            q.pop();
            int currNode = curr.first; // Current node.
            int currMask = curr.second.first; // Bitmask representing visited nodes.
            int currLength = curr.second.second; // Length of the current path.
            // If all nodes are visited, return the path length.
            if(currMask==mask) 
                return currLength - 1; //Subtract 1 for number of edges,not nodes
            // Explore neighbors of the current node.
            for (int i = 0; i < graph[currNode].size(); i++) 
            {
                int neighbor = graph[currNode][i]; // Neighbor node.
                // Update bitmask for neighbor by setting corresponding bit to 1.
                int newMask = currMask | (1 << neighbor);
                // If the neighbor node is already visited with this bitmask, skip.
                if (visited[newMask][neighbor])
                    continue;
                // Push neighbor into queue with updated bitmask and length.
                q.push({neighbor, {newMask, currLength + 1}});
                // Mark the neighbor as visited with the new bitmask.
                visited[newMask][neighbor] = true;
            }
        }
        // If no path visiting all nodes is found, return -1.
        return -1; 
    }
};
