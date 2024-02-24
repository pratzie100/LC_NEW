class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int c=1;
        int n=nums.size();
        int x=nums[0]+nums[1];
        for(int i=2;i<n;i+=2)
        {
            int z;
            if(!(i+1>n-1))
            {    z=nums[i]+nums[i+1];
            if(x==z) c++;
            else break;}
        }
        return c;
    }
};