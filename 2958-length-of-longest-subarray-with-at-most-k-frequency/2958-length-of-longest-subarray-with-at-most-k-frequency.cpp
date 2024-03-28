class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        int n=nums.size();
        //for(int i:nums)m[i]++;
        int l=0,r=0;
        int ans=INT_MIN;
        for(int r=0;r<n;r++)
        {
            m[nums[r]]++;

                while(m[nums[r]]>k)
                {
                    m[nums[l]]--;
                    l++;
                }
            
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};