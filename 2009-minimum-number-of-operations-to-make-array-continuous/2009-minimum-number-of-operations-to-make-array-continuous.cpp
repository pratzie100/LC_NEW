class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        //sort(begin(nums),end(nums));
        set<int>s(begin(nums),end(nums));
        nums.clear();
        for(int i:s)//remove duplicates
        {
            nums.push_back(i);
        }
        int ans=n;
        for(int i=0;i<n;i++)
        {
            int x=nums[i]+n-1;
            int ind=upper_bound(begin(nums),end(nums),x)-begin(nums);
            ans=min(ans,n-ind+i);
        }
        return ans;
    }
};

