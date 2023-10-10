class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX; 
        sort(nums.begin(), nums.end()); 
        nums.erase(unique(begin(nums),end(nums)),end(nums)); 
        int end=0; // Initialize a variable 'end' to keep track of the end index.
        for(int l = 0, r = 0; l<nums.size(); l++) 
        {
            // Loop through the unique elements in the sorted vector.
            while(r<nums.size() && nums[r]<nums[l]+n) 
            {
                // While 'end' is within bounds and the current element plus 'n' is greater
                // than the element at 'start', continue this loop.

                // Step 1: Increment 'end' by 1 to extend the subarray to the right.
                r++;
                // Step 2: Calculate the length of the subarray.
                int subarrayLength = r - l;
                // Step 3: Calculate the number of operations needed to maintain consecutive integers.
                int operationsNeeded = n - subarrayLength;
                // Update 'ans' with min number of operations found so far.
                ans = min(ans, operationsNeeded);
            }
        }
        return ans; // Return the minimum number of operations.
    }
};
