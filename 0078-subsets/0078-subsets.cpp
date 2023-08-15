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

//using bit manipulation
    // vector<vector<int>>subsets(vector<int>& nums) {
    //     int n=nums.size();
    //     vector<vector<int>>ans;
    //     for(int i=0;i<(1<<n);i++) //1<<n -> 2^n
    //     {
    //         vector<int>subset;
    //         for(int j=0;j<n;j++) 
    //         {
    //             if (i&(1<<j)) //checks if the j-th bit of the integer i is set to 1 or 0.
    //                 subset.push_back(nums[j]); 
    //         }
    //         ans.push_back(subset);
    //     }
    //     return ans;
    // }
};