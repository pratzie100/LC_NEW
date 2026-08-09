class Solution {
public: 
    // // unordered_map<int,int>memo;  (can take global memo too)
    // int prat(int n,unordered_map<int,int>&memo){
    //     if(memo.count(n)) return memo[n];
    //     if(n==1) return 1;
    //     if(n==2) return 2;
    //     int ans= prat(n-1,memo) + prat(n-2,memo);
    //     memo[n]=ans;
    //     return ans;
    // }

    // int climbStairs(int n) {
    //     unordered_map<int,int>memo;
    //     return prat(n,memo);
    // }



    int climbStairs(int n) {
       vector<int>dp(n+2); //n+1 error for n=1 since dp[2] not defined
       dp[1]=1;
       dp[2]=2;
       for(int i=3;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
       } 
       return dp[n];
    }
};