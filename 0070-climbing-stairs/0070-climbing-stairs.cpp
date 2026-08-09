class Solution {
public: 
    // unordered_map<int,int>memo;
    int prat(int n,unordered_map<int,int>&memo){
        if(memo.count(n)) return memo[n];
        if(n==1) return 1;
        if(n==2) return 2;
        int ans= prat(n-1,memo) + prat(n-2,memo);
        memo[n]=ans;
        return ans;
    }

    int climbStairs(int n) {
        unordered_map<int,int>memo;
        return prat(n,memo);
    }
};