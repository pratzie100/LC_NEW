class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int>x;
        for(string s:bank)
        {
            int one=0;
            for(int i=0;i<s.size();i++)
            {
                if(s[i]=='1') one++;
            }
            x.push_back(one);
        }
        int ans=0;
        for(int i=0;i<x.size();i++)
        {
            if(x[i]==0) continue;
            for(int j=i+1;j<x.size();j++)
            {
                if(x[j]==0) continue;
                ans+=x[i]*x[j];
                break;
            }
        }
        return ans;
    }
};