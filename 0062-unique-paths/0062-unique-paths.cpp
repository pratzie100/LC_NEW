class Solution {
public:
    int solve(int i,int j,vector<vector<int>>&dp,int m,int n)
    {
        if(i==m-1&&j==n-1) 
            return 1; //found one path
        
        if(i>=m||j>=n) // since only down and right movement is allowed
             return 0; //didnt find correct path , return 0
        
        if(dp[i][j]!=-1) //if already computed
            return dp[i][j];
        
        int down=solve(i+1,j,dp,m,n);
        int right=solve(i,j+1,dp,m,n);
        return dp[i][j]=down+right;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return solve(0,0,dp,m,n);
    }
};