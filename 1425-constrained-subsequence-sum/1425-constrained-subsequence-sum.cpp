class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int, int>> maxHeap; // Max heap to store 
        // (max sum ending at index i, index i of element that contributed) in the sliding window
        vector<int> dp(n); // dp[i] represents the max sum ending at index i
        int ans = INT_MIN;
        for (int i = 0; i < n; i++) 
        {
            //5. Remove contribution of those elements that are out of the sliding window (i - k)
            while (!maxHeap.empty() && maxHeap.top().second < i - k) {
                maxHeap.pop();
            }
            //3. for current what i need
            int prevMax = maxHeap.empty() ? 0 : maxHeap.top().first;
            //2. currently what i need to do
            dp[i] = max(nums[i], nums[i] + prevMax);
            //4. overall what i need to do
            ans = max(ans, dp[i]);
            //1. what to push to maximize
            maxHeap.push({dp[i], i});
        }
        return ans;
    }
};