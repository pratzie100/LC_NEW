class Solution {
public:
    // vector<vector<int>>ans;
    // void solve(int ind,vector<int>&ds,vector<int>&nums)
    // {
    //     if(ind==nums.size())
    //     {
    //         ans.push_back(ds);
    //         return;
    //     }
    //     //pick case:Include the current number in the subset and proceed to the next index.
    //     ds.push_back(nums[ind]);
    //     solve(ind+1,ds,nums);
    //     //Notpick case:Exclude the current number in the subset and proceed to the next index.
    //     ds.pop_back(); // Backtrack by removing the last element from the subset.
    //     solve(ind+1,ds,nums);
    // }
    // vector<vector<int>> subsets(vector<int>& nums) {
    //     vector<int>ds;
    //     solve(0,ds,nums);
    //     return ans;
    // }

//using bit manipulation
//Suppose you have a set of elements nums = [3, 5, 8] and n = 3. The bit representation of the integers from 0 to 7 (inclusive) is as follows:
// 0: 000 -> Empty subset {}.
// 1: 001 -> Subset {8}.
// 2: 010 -> Subset {5}.
// 3: 011 -> Subset {5, 8}.
// 4: 100 -> Subset {3}.
// 5: 101 -> Subset {3, 8}.
// 6: 110 -> Subset {3, 5}.
// 7: 111 -> Subset {3, 5, 8}
    vector<vector<int>>subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        //2^n subsets of n elements can be represented by 2^n binary representations 
        for(int i=0;i<(1<<n);i++) //1<<n represents 2^n
        {
            vector<int>subset;
            for(int j=0;j<n;j++) 
            {
                // (i >> j) shifts the bits of i to the right by j positions, making the j-th bit the least significant bit. Then, the & 1 operation is performed to check if the least significant bit is set to 1.
                if((i>>j)&1) //checks if the j-th bit of the integer i is set to 1 or 0.
                    subset.push_back(nums[j]); 
            }
            ans.push_back(subset);
        }
        return ans;
    }
};