class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        set<int>s;
        for(auto i:nums)
        {
            for(int j=i[0];j<=i[1];j++)
                s.insert(j);
        }
        return s.size();
    }
};