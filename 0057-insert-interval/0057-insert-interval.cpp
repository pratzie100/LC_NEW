class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>p, vector<int>& k) {
        vector<vector<int>>v;
        int n=p.size();
        int i=0;
        for(;i<n;i++)
        {
            if(p[i][1]<k[0])v.push_back(p[i]);
            else break;
        }
        for(;i<n;i++)
        {
            if(p[i][0]<=k[1])
            {
                k[0]=min(k[0],p[i][0]);
                k[1]=max(k[1],p[i][1]);
            }
            else break;
        }
        v.push_back(k);
        for(;i<n;i++) v.push_back(p[i]);
        return v;
        
    }
};
