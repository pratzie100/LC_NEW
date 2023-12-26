class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<long long>>dp(n + 1, vector<long long>(target + 1, 0));
        dp[0][0] = 1;
        const int mod = 1000000007;
        for (int dice = 1; dice <= n; dice++) {
            for (int tar = 1; tar <= target; tar++) {
                long long ans = 0;
                for (int i = 1; i <= k && i <= tar; i++) {
                    ans += (dp[dice - 1][tar - i] % mod);
                }
                dp[dice][tar] = (ans % mod);
            }
        }

        return int(dp[n][target]);
    }
};