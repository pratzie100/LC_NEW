class Solution {
public:
    bool solve(int i,int j,int k,vector<vector<int>>&dp,string &s1,string &s2,string &s3)
    {
        if(i<0 && j<0 && k<0) return true;
        if(i>=0 && j>=0 && dp[i][j]!=-1) return dp[i][j];
        if(i>=0 && s1[i]==s3[k] && j>=0 && s2[j]==s3[k])
        {
            bool ans1=solve(i-1,j,k-1,dp,s1,s2,s3);
            bool ans2=solve(i,j-1,k-1,dp,s1,s2,s3);
            return dp[i][j]=ans1 || ans2;
        }
        else if(i>=0 && s1[i]==s3[k])
            return solve(i-1,j,k-1,dp,s1,s2,s3);
        else if(j>=0 && s2[j]==s3[k])
            return solve(i,j-1,k-1,dp,s1,s2,s3);
        else return false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int m=s1.size();
        int n=s2.size();
        int l=s3.size();
        if(l!=m+n) return false;
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return solve(m-1,n-1,l-1,dp,s1,s2,s3);
    }
};