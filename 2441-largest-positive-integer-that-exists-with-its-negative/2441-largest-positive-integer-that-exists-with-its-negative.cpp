class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int>s(begin(nums),end(nums));
        int maxi=INT_MIN;
        for(int c:s)
        {
            if(s.count(c)&&s.count(-c))
            maxi=max(maxi,c);
        }
        return maxi==INT_MIN?-1:maxi;
    }
};