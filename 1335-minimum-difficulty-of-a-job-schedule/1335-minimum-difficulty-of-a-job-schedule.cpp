class Solution {
public:

    int solve(vector<int>&job, int index, int k, int d, int n, vector<vector<int>>&dp) {
        if(index==n && k==d) {
            return 0;
        }
        if(index==n && k<d  || index<n && k==d) {
            return INT_MAX;
        }
        if(dp[index][k]!=-1) {
            return dp[index][k];
        }
        int ans = INT_MAX;
        int maxi = INT_MIN;
        for(int i=index; i<n; i++) {
            maxi = max(maxi,job[i]);
            int t = solve(job,i+1,k+1,d,n,dp);
            if(t!=INT_MAX) {
                ans = min(ans,maxi+t);
            }
        }
        return dp[index][k]=ans;
    }

    int minDifficulty(vector<int>& job, int d) {
        int n = job.size();
        vector<vector<int>>dp(n,vector<int>(d+1,-1));
        int fina = solve(job,0,0,d,job.size(),dp);
        if(fina==INT_MAX) {
            return -1;
        }
        return fina;
    }
};