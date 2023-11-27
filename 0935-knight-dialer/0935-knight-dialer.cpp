class Solution {
public:
    map<int,vector<int>> mp;
    int M = 1e9 + 7;
    long f(int i,int n,vector<vector<int>> &dp){
        if(n==0){
            return 1;
        }
        if(dp[i][n]!=-1) return dp[i][n];
        long cnt = 0;
        for(auto &it:mp[i]){ 
            cnt += f(it,n-1,dp);
        }
        cnt %= M;
        return dp[i][n] = cnt;
    }

    int knightDialer(int n) {
       
        mp[0] = {4,6};
        mp[1] = {8,6};
        mp[2] = {7,9};
        mp[3] = {4,8};
        mp[4] = {0,3,9};
        mp[5] = {};
        mp[6] = {0,1,7};
        mp[7] = {2,6};
        mp[8] = {1,3};
        mp[9] = {2,4}; 
        vector<vector<int>> dp(10,vector<int>(n,-1));
        int ans = 0;
        for(int i=0;i<=9;i++){
            ans += f(i,n-1,dp);
            ans %= M;
        }     

        return ans;
    }
};