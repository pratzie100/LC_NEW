class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int xorr=0;
        for(int i:nums)xorr^=i;
        return __builtin_popcount(xorr^k);
    }
};
// 010
// 001
// 011
// 100
//     =111..001