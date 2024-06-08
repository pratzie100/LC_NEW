class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0]=-1;
        int s=0;
        for(int i=0;i<nums.size();i++){
            s+=nums[i];
            int rem=s%k;
            if(rem<0)rem+=k;
            if(mp.count(rem)){
                if(i-mp[rem]>=2) return true;
            }
            else mp[rem]=i;
        }
        return false;
    }
};