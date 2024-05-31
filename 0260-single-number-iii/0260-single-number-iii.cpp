class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // unordered_map<int,int>m;
        // for(int i:nums){m[i]++;}
        // vector<int>ans;
        // for(auto i:m){if(i.second==1)ans.push_back(i.first);};
        // return ans;
        vector<int>ans;
        sort(begin(nums),end(nums));
        if(nums[1]!=nums[0]) ans.push_back(nums[0]);
        int n=nums.size();
        int c=0;
        for(int i=1;i<n-1;i++)
        {
            if(nums[i]!=nums[i-1] && nums[i]!=nums[i+1]) 
                    ans.push_back(nums[i]);
        }
        if(nums[n-1]!=nums[n-2]) ans.push_back(nums[n-1]);
        return ans;
    }
};
// 1 1 2 2 3 4 4 5
// 1 2 