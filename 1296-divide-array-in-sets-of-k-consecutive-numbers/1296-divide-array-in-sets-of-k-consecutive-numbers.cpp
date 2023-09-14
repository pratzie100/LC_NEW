class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if(nums.size()%k!=0) return false;
        map<int,int>m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        sort(begin(nums),end(nums));
        for(int num:nums)
        {
            if(m[num]>0)
            {
                for(int i=0;i<k;i++)
                {
                    int nextnum=num+i;
                    if(m[nextnum]<=0) return false;
                    m[nextnum]--;
                }
            }
        }
        return true;
    }
};
