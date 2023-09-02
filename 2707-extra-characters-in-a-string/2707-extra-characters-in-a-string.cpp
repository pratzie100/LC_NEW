class Solution {
public:
    int solve(int ind,vector<int>&dp, unordered_map<string,int>&m,string&s)
    {
        if(ind>=s.size()) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int ans=INT_MAX;
        string subs= "";
        for(int i=ind;i<s.size();i++)
        {
            subs.push_back(s[i]);
            int extraCount=0;
            if(m.count(subs)) extraCount=solve(i+1,dp,m,s);
            else extraCount=subs.size()+solve(i+1,dp,m,s); 
            ans=min(ans,extraCount);
        }
        return dp[ind]=ans;
    }
    int minExtraChar(string s, vector<string>& dictionary) 
    {
        unordered_map<string,int>m;
        for(string word:dictionary) m[word]++;
        vector<int>dp(s.size(),-1);
        return solve(0,dp,m,s);  
    }
};
