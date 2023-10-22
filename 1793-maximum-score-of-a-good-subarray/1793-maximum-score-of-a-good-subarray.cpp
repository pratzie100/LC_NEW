class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        int left = k;
        int right = k;
        int ans = nums[k]; // Initialize the answer with the value at index k
        int currMin = nums[k]; // Initialize the current minimum with the value at index k

        // Continue the loop as long as either 'left' is greater than 0 or 'right' is less than n - 1
        while (left > 0 || right < n - 1) {
            // Calculate the value to the left of 'left' and to the right of 'right'
            int leftValue = (left > 0) ? nums[left - 1] : 0;
            int rightValue = (right < n - 1) ? nums[right + 1] : 0;

            if (leftValue < rightValue) {
                // Move 'right' to the right and update 'currMin' if a larger value is found
                right++;
                currMin = min(currMin, nums[right]);
            } 
            else {
                // Move 'left' to the left and update 'currMin' if a larger value is found
                left--;
                currMin = min(currMin, nums[left]);
            }

            // Calculate the current score, considering the current 'currMin' and range width
            int currentScore = currMin * (right - left + 1);

            // Update 'ans' with the maximum of the current score and the previous maximum score
            ans = max(ans, currentScore);
        }

        // Return the maximum score found during the exploration
        return ans;
    }
};
