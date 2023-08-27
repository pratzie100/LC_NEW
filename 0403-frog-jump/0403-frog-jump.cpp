class Solution {
public:
    bool solve(int lastIndex, int currentIndex,vector<vector<int>>&dp,vector<int>&stones) {
        if(currentIndex == stones.size()-1) return true;
        if(dp[lastIndex][currentIndex]) return false;
        
        int lastJump = stones[currentIndex] - stones[lastIndex];
        int nextIndex = currentIndex + 1;
        while(nextIndex < stones.size() && stones[nextIndex] <= stones[currentIndex] + lastJump + 1) 
        {
            int nextJump = stones[nextIndex] - stones[currentIndex];
            int jump = nextJump - lastJump;
            if (jump >= -1 && jump <= 1) 
            {
                if(solve(currentIndex, nextIndex,dp,stones)) 
                return true;       
            }
            nextIndex++;
        }
        dp[lastIndex][currentIndex] = true;
        return false;
    }
    bool canCross(vector<int>& stones) {
        if(stones[1]!=1)  return false;
        int n=stones.size();
        vector<vector<int>>dp(n,vector<int>(n,false));
        return solve(0,1,dp,stones);
    }
};