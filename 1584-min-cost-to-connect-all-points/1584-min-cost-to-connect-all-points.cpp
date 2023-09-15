class Solution {
public:
    vector<int> parent;
    void make_set(int v)  
    {
        parent[v] = v;
    }
    int find_set(int v)
    {
        if(v==parent[v])
            return v;
        else    
            return parent[v] = find_set(parent[v]); //path compression
    }

    void union_sets(int u, int v) // union two sets by attaching one to other
    {
        int a = find_set(u);
        int b = find_set(v);
        if (a != b)
        {
            parent[b] = a;
        }
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<int>> edges;
        parent.resize(n); // Resize parent array according to the number of points
        for (int i = 0; i < n; i++) 
        {
            make_set(i);
        }
        
        for (int i = 0; i < n-1; i++) 
        {
            for (int j = i + 1; j < n; j++) 
            {
                int cost=abs(points[i][0]-points[j][0])+abs(points[i][1]- points[j][1]);
                edges.push_back({i, j, cost});
            }
        }
        //now apply kruskal algorithm
        sort(begin(edges), end(edges), [](vector<int>& a, vector<int>& b) {
            return a[2] < b[2];
        });

        int minCost = 0;
        for (auto edge : edges) 
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            int parentU = find_set(u);
            int parentV = find_set(v);
            //If the endpoints of the edge belong to different sets, connect them
            if (parentU != parentV) 
            {
                minCost += w;
                union_sets(parentU, parentV);
            }
        }
        return minCost;
    }
};
