class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(begin(s),end(s));
        sort(begin(g),end(g));
        // for(int i=0;i<g.size();i++)
        // {
        int i=0;
        int c=0;
            for(int j=0;j<s.size();j++)
            {
                if(s[j]>=g[i])
                {
                   i++;
                    c++;
                    if(i==g.size()) break;
                }
            }
        return c;
       // }
    }
};