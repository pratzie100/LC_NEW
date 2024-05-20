class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        for(int mask=0;mask<(1<<n);mask++)
        {
            vector<int>v;
            for(int i=0;i<n;i++)
            {
                if((mask>>i)&1)
                {
                    v.push_back(nums[i]);
                }
            }
            ans.push_back(v);           
        }
        int x=0;
        for(int i=0;i<ans.size();i++)
        {
            vector<int>v=ans[i];
            int c=0;
            for(int k:v)
            {
                c^=k;
            }
            x+=c;
        }
        return x;
    }
};