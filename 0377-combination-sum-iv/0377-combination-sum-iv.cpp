class Solution {
public:
    int combinationSum4(std::vector<int>& nums, int target) {
        vector<int>dp(target+1,-1);
        dp[0]=1;
        return solve(dp,target,nums);
    }

    int solve(vector<int>& dp,int target,vector<int>&nums) {
        if(dp[target]!=-1) return dp[target];
        int ans = 0;
        for (int i=0; i<nums.size(); i++) 
        {
            if (target - nums[i] >= 0) 
                ans+=solve(dp,target-nums[i],nums);
        }
        return dp[target]=ans;
    }
};
