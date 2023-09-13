class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int count=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i!=j)
                {
                    string s1=nums[i];
                    string s2=nums[j];
                    if(s1+s2==target)
                        count++;
                }
            }
        }
        return count;
    }
};