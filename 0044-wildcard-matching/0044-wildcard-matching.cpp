class Solution {
public:
    //recursive tle
    // bool solve(int i, int j, string p, string s) {
    //     if(i<0 && j<0) return true;
    //     if(i<0 && j>=0) return false;
    //     if(j<0 && i>=0) 
    //     {
    //         for(int k=0; k<=i;k++) 
    //         {
    //             if(p[k]!='*') return false;
    //         }
    //         return true;
    //     }
    //     if(p[i]==s[j] || p[i]=='?') 
    //         return solve(i-1,j-1,p,s);
    //     if(p[i]=='*') // Skip '*' in pattern or skip character in string
    //         return solve(i-1,j,p,s)||solve(i,j-1,p,s)||solve(i-1,j-1,p,s);
    //     return false;
    // }
    // bool isMatch(string s, string p) {
    //     int n=p.size();
    //     int m=s.size();
    //     return solve(n-1,m-1,p,s);
    // }

    //memoization tle
    // bool solve(int i, int j, string p, string s,vector<vector<int>>&dp) {
    //     if(i<0 && j<0) return true; //both strings exhausted
    //     if(i<0 && j>=0) return false; //pattern exhausted,string remains
    //     if(j<0 && i>=0) //string exhausted,pattern remaining
    //     {
    //         for(int k=0; k<=i;k++) 
    //         {
    //             //since '*' signifies sequence of length 0 or more
    //             if(p[k]!='*') return false;
    //         }
    //         return true;
    //     }
    //     if(dp[i][j]!=-1) return dp[i][j]; //already compute
        
    //     if(p[i]==s[j] || p[i]=='?') 
    //         return dp[i][j]=solve(i-1,j-1,p,s,dp);
    //     if(p[i]=='*') // Skip '*' in pattern or skip character in string
    //         return dp[i][j]=solve(i-1,j,p,s,dp)||solve(i,j-1,p,s,dp)||solve(i-1,j-1,p,s,dp);
    //     return dp[i][j]=false;
    // }
    // bool isMatch(string s, string p) {
    //     int n=p.size();
    //     int m=s.size();
    //     vector<vector<int>>dp(n,vector<int>(m,-1));
    //     return solve(n-1,m-1,p,s,dp);
    // }

    bool isMatch(string s, string p) {
        int n = p.size();
        int m = s.size();
        vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));
        dp[0][0] = true;  // Empty pattern and empty string match
        //length based indexing for tabulation
        for(int j=1;j<=m;j++) //pattern exhausted,string remains
            dp[0][j]=false;
        for(int i=1;i<=n;i++) //string exhausted,pattern remaining
        {
            bool flag=true;
            for(int k=0;k<i;k++) 
            {
                if(p[k]!='*')
                {
                    flag=false;
                    break;
                }
            }             
            dp[i][0]=flag;
        }

        for(int i=1;i<=n;i++) 
        {
            for(int j=1;j<=m;j++) 
            {
                if(p[i-1]==s[j-1] || p[i-1]=='?') 
                    dp[i][j]=dp[i-1][j-1];
                else if(p[i-1]=='*') 
                    dp[i][j]=dp[i-1][j] || dp[i][j-1];
                else dp[i][j]=false;
            }
        }
        return dp[n][m];
    }
};