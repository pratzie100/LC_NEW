class Solution {
public:
//same as 1296
    bool isNStraightHand(vector<int>& nums, int k) {
        if(nums.size()%k!=0) return false;
        map<int,int>m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        sort(begin(nums),end(nums));
        for(int i=0;i<nums.size();i++)
        {
            if(m[nums[i]]>0)
            {
                for(int j=0;j<k;j++)
                {
                    if(m[nums[i]+j]<=0) return false;
                    m[nums[i]+j]--;
                }
            }
        }
        return true;
    }
};