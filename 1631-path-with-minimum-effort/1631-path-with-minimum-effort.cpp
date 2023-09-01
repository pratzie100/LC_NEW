class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        priority_queue
        <
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
        >pq;
        vector<vector<int>>dist(m,vector<int>(n,INT_MAX));
        dist[0][0]=0;
        pq.push({0,{0,0}});
        vector<vector<int>>moves{{1,0},{-1,0},{0,1},{0,-1}};
        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            int diff=it.first;
            int i=it.second.first;
            int j=it.second.second;
            if(i==m-1 && j==n-1) return diff;
            for(int k=0;k<moves.size();k++)
            {
                int newi=i+moves[k][0];
                int newj=j+moves[k][1];
                if(newi>=0 && newi<m && newj>=0 && newj<n)
                {
                    int newEffort=max(diff,abs(heights[i][j]-heights[newi][newj]));
                    if(newEffort < dist[newi][newj])
                    {
                        pq.push({newEffort,{newi,newj}});
                        dist[newi][newj]=newEffort;
                    }
                }
            }
        }
        return 0;
    }
};