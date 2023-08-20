class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        if(nums.size()==1) return 1;
        unordered_map<int,int>m;
        int l=0,t=0,maxi=0;
        for(int r=0;r<nums.size();r++)
        {
            m[nums[r]]++;
            t=max(t,m[nums[r]]); //max freq of single element within current window
            int todelete=(r-l+1)-t;
            if(todelete>k)
            {
                m[nums[l]]--; //reduce window size
                l++;
            }
            maxi=max(maxi,t); // overall answer
        }
        return maxi;
    }
};
