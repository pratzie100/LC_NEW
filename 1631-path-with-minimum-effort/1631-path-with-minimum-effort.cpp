// class Solution {
// public:
//     int minimumEffortPath(vector<vector<int>>& heights) {
//         int m=heights.size();
//         int n=heights[0].size();
//         priority_queue
//         <
//             pair<int,pair<int,int>>,
//             vector<pair<int,pair<int,int>>>,
//             greater<pair<int,pair<int,int>>>
//         >pq;
//         vector<vector<int>>dist(m,vector<int>(n,INT_MAX));
//         dist[0][0]=0;
//         pq.push({0,{0,0}});
//         vector<vector<int>>moves{{1,0},{-1,0},{0,1},{0,-1}};
//         while(!pq.empty())
//         {
//             auto it=pq.top();
//             pq.pop();
//             int diff=it.first;
//             int i=it.second.first;
//             int j=it.second.second;
//             if(i==m-1 && j==n-1) return diff;
//             for(int k=0;k<moves.size();k++)
//             {
//                 int newi=i+moves[k][0];
//                 int newj=j+moves[k][1];
//                 if(newi>=0 && newi<m && newj>=0 && newj<n)
//                 {
//                     int newEffort=max(diff,abs(heights[i][j]-heights[newi][newj]));
//                     if(newEffort < dist[newi][newj])
//                     {
//                         pq.push({newEffort,{newi,newj}});
//                         dist[newi][newj]=newEffort;
//                     }
//                 }
//             }
//         }
//         return 0;
//     }
// };
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        int left = 0;
        int right = 1e6; // Set an initial upper bound for binary search
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            vector<vector<bool>> visited(m, vector<bool>(n, false));
            
            if (dfs(heights, 0, 0, mid, visited, m, n)) {
                // If a path is found with max difference <= mid, try to find a smaller bound
                right = mid;
            } else {
                // If no path is found with max difference <= mid, increase the bound
                left = mid + 1;
            }
        }
        
        return left;
    }
    
    bool dfs(vector<vector<int>>& heights, int i, int j, int maxDiff, vector<vector<bool>>& visited, int m, int n) {
        if (i == m - 1 && j == n - 1) {
            return true; // Reached the destination
        }
        
        visited[i][j] = true;
        int moves[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        for (const auto& move : moves) {
            int newi = i + move[0];
            int newj = j + move[1];
            
            if (newi >= 0 && newi < m && newj >= 0 && newj < n && !visited[newi][newj]) {
                int diff = abs(heights[i][j] - heights[newi][newj]);
                if (diff <= maxDiff && dfs(heights, newi, newj, maxDiff, visited, m, n)) {
                    return true;
                }
            }
        }
        
        return false;
    }
};
