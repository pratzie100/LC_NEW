class Solution {
public:
    vector<vector<int>>ans;
    void solve(int ind,vector<int>&ds,vector<int>&nums)
    {
        if(ind==nums.size())
        {
            ans.push_back(ds);
            return;
        }
        //pick case:Include the current number in the subset and proceed to the next index.
        ds.push_back(nums[ind]);
        solve(ind+1,ds,nums);
        //Notpick case:Exclude the current number in the subset and proceed to the next index.
        ds.pop_back(); // Backtrack by removing the last element from the subset.
        solve(ind+1,ds,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>ds;
        solve(0,ds,nums);
        return ans;
    }
};