class Solution {
public:
    int missingNumber(vector<int>& nums) {
       int n=nums.size();
        long long acc=accumulate(begin(nums),end(nums),0LL);
        if(acc==(n*(n+1))/2) return 0;
        else return (n*(n+1)/2)-acc;
    }
};