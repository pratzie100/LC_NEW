class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans=INT_MIN;
        for(int i=0;i<nums.size()-2;i++)
        {
            for(int j=i+1;j<nums.size()-1;j++)
            {
                for(int k=j+1;k<nums.size();k++)
                {
                    long long val=(long long)(nums[i]-nums[j])*nums[k];
                    ans=max(ans,val);
                }
            }
        }
        if(ans<0) return 0;
        return ans;
    }
};