class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        unordered_map<int,vector<int>>g;
        vector<int>ind(n,0);
        for(vector<int>v:relations)
        {
            int x=v[0]-1;
            int y=v[1]-1;
            g[x].push_back(y);
            ind[y]++;
        }
        vector<int>maxtime(n,0);
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(ind[i]==0)
            {
                q.push(i);
                maxtime[i]=time[i];
            }
        }
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(int x:g[node])
            {
                maxtime[x]=max(maxtime[x],maxtime[node]+time[x]);
                ind[x]--;
                if(ind[x]==0)
                {
                    q.push(x);
                }
            }
        }
        return *max_element(begin(maxtime),end(maxtime));
    }
};