class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        set<int>s;
        for(int i=1;i<=k;i++)
        {
            s.insert(i);
        }
        int count=0;
        int n=nums.size();
        for(int i=n-1;i>=0;i--)
        {
            if(s.find(nums[i])!=s.end())
            {
                k--;
                s.erase(nums[i]);
                if(k==0)
                {
                    count++;
                 break;
                }
            }
            count++;
        }
        return count;
    }
};