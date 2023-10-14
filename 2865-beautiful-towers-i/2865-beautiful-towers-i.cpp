class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int n = maxHeights.size();
        long long maxSum = 0;
        for (int i = 0; i < n; i++) 
        {
            int currentMaxHeight = maxHeights[i];
            long long leftSum = 0, rightSum = 0;
            int prevHeight = currentMaxHeight;
            // Calculate left sum
            for (int j = i; j >= 0; j--) 
            {
                prevHeight = min(prevHeight, maxHeights[j]);
                leftSum += prevHeight;
            }            
            prevHeight = currentMaxHeight;
            // Calculate right sum
            for (int j = i; j < n; j++) 
            {
                prevHeight = min(prevHeight, maxHeights[j]);
                rightSum += prevHeight;
            }
            maxSum = max(maxSum, leftSum + rightSum - currentMaxHeight);
        }
        return maxSum;
    }
};
