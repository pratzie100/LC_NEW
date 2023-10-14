class Solution {
public:
    int n;
    int paintWalls(vector<int>& cost, vector<int>& time) {
        n=cost.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(0,n,dp,cost,time);
    }
    int solve(int i,int remain,vector<vector<int>>&dp,vector<int>& cost,vector<int>& time){ 
        if(remain<=0) return 0;
        if(i==n) return 1e9;
        if(dp[i][remain]!=-1) return dp[i][remain];
        int paint = cost[i] + solve(i+1,remain-1-time[i],dp,cost,time);
        int dontPaint = solve(i+1,remain,dp,cost,time);
        return dp[i][remain] = min(paint, dontPaint);
    }
};
