class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        unordered_map<int,int>m;
        m[0]=1;
        long long count = 0;
        long long c = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%modulo==k) 
                c++;
            count+=m[(c-k+modulo)%modulo];
            m[c%modulo]++;
        }
        return count;
    }
};
