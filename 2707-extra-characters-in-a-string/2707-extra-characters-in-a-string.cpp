class Solution {
public:
    int solve(int ind,vector<int>&dp, unordered_map<string,int>&m,string&s)
    {
        if(ind>=s.size()) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int ans=INT_MAX;
        string subs=""; //current substring
        for(int i=ind;i<s.size();i++)
        {
            subs+=s[i];
            int extraCount=0;
            //if current substring present in dictionary
            if(m.count(subs)) extraCount=solve(i+1,dp,m,s); //no extra chars needed
            
            else extraCount=subs.size()+solve(i+1,dp,m,s); //else calculate extra chars needed as = size of current substring + extra characters needed for rest of string.
            
            // Update 'ans' with minimum extra chars seen so far
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
