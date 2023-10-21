// class Solution {
// public:
//     int constrainedSubsetSum(vector<int>& nums, int k) {
//         Use dynamic programming.
//             Let dp[i] be the solution for the prefix of the array that ends at index i, if the element at index i is in the subsequence.
//             dp[i] = nums[i] + max(0, dp[i-k], dp[i-k+1], ..., dp[i-1])
//             Use a heap with the sliding window technique to optimize the dp.
//     }
// };
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n); // dp[i] represents the maximum sum ending at index i

        priority_queue<pair<int, int>> maxHeap; // Max heap to store the maximum dp values in the sliding window

        int maxSum = INT_MIN;

        for (int i = 0; i < n; i++) 
        {
            // Remove contribution of those elements that are out of the sliding window (i - k)
            while (!maxHeap.empty() && maxHeap.top().second < i - k) {
                maxHeap.pop();
            }
            //for current what i need
            int prevMax = maxHeap.empty() ? 0 : maxHeap.top().first;
            //currently what i need to do
            dp[i] = max(nums[i], nums[i] + prevMax);
            //overall what i need to do
            maxSum = max(maxSum, dp[i]);
            //what to push to maximize
            maxHeap.push({dp[i], i});
        }
        return maxSum;
    }
};
