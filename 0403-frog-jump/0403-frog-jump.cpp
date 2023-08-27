class Solution {
public:
vector<vector<bool>> dp;

bool helper(const vector<int>& stones, int lastIndex, int currentIndex) {
    if (currentIndex == stones.size() - 1) {
        return true;
    }

    if (dp[lastIndex][currentIndex]) {
        return false;
    }

    int lastJump = stones[currentIndex] - stones[lastIndex];

    int nextIndex = currentIndex + 1;

    while (nextIndex < stones.size() && stones[nextIndex] <= stones[currentIndex] + lastJump + 1) {
        int nextJump = stones[nextIndex] - stones[currentIndex];
        int jump = nextJump - lastJump;

        if (jump >= -1 && jump <= 1) {
            if (helper(stones, currentIndex, nextIndex)) {
                return true;
            }
        }
        nextIndex++;
    }

    dp[lastIndex][currentIndex] = true;

    return false;
}

    bool canCross(vector<int>& stones) {
        if(stones[1] != 1)  return false;
        int n = stones.size();
        dp = vector<vector<bool>>(n, vector<bool>(n, false));   
        return helper(stones, 0, 1);
    }
};