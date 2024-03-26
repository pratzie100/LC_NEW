class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int>s(begin(nums),end(nums));
        for(int i=1;;i++){if(!s.count(i))return i;}
    }
};