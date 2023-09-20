class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int totalSum = accumulate(begin(nums), end(nums), 0); // Calculate the total sum of nums
        int target = totalSum - x; // Calculate the target difference
        if (target < 0)
            return -1; // If target is negative, it's not achievable
        if (target == 0)
            return n; // If target is zero, no operations needed, return the number of elements
        int minOps = INT_MAX; // Initialize minOps to a large value
        int left = 0, right = 0, currSum = 0; // Initialize pointers and current sum
        while (right < n)
        {
            currSum += nums[right]; // Expand the window to the right
            right++;
            while (currSum > target && left < n)
            {
                currSum -= nums[left]; // Contract the window from the left
                left++;
            }
            if (currSum == target)
            {
                minOps = min(minOps, n - (right - left)); // Update minOps if target is achieved
            }
        }
        return (minOps == INT_MAX) ? -1 : minOps; // Return minOps or -1 if not achievable
    }
};
