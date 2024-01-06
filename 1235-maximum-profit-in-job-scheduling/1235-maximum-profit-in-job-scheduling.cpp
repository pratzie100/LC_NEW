class Solution {
public:
    static bool compare(const vector<int>& v1, const vector<int>& v2){
        return v1[1] < v2[1];
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        int i, j;

        vector<vector<int>> vec(n, vector<int>(3));
        for(i = 0; i < n; i++){
            vec[i][0] = startTime[i];
            vec[i][1] = endTime[i];
            vec[i][2] = profit[i];
        }

        sort(vec.begin(), vec.end(), compare);
        vector<int> dp(n);

        dp[0] = vec[0][2];
        int maxProfit = vec[0][2];

        for(i = 1; i < n; i++){
            vector<int> temp = {vec[i][0], vec[i][0], vec[i][0]};
            auto it = upper_bound(vec.begin(), vec.end(), temp, compare);
            if(it == vec.begin()){
                dp[i] = max(dp[i - 1], vec[i][2]);
            }
            else{
                --it;
                j = it - vec.begin();
                dp[i] = max(dp[i - 1], dp[j] + vec[i][2]);
            }
            maxProfit = max(maxProfit, dp[i]);
        }

        return maxProfit;
    }
};