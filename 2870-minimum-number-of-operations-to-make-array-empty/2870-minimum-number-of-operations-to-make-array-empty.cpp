class Solution {
public:

    int minOperations(vector<int>& nums) {
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        int count=0;
        for(auto i:m)
        {
            if(i.second==1) return -1;
            else
            {
                if(i.second%3==0)
                    count+=i.second/3;
                else
                    count+=(i.second/3)+1;
            }
        }
        return count;
        
    }
};