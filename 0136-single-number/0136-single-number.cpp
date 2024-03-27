class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //o(n) space - map
        int ans=0;
        for(int i:nums) ans^=i;
        return ans;
    }
};