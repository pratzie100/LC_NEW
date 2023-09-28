class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int>ans(nums);
        sort(begin(ans),end(ans),[&](int &a,int &b){
            if(a%2==0 && b%2!=0) return true; 
            if(a%2!=0 && b%2==0) return false; 
            return a<b;
        });
        return ans;
        
        
        // vector<int> ans;
        // for(int i=0;i<nums.size();i++)
        // {
        //     if(nums[i]%2==0)
        //     {
        //         ans.push_back(nums[i]);
        //     }
        // }
        // for(int i=0;i<nums.size();i++)
        // {
        //     if(nums[i]%2!=0)
        //     {
        //         ans.push_back(nums[i]);
        //     }
        // }
        // return ans;
    }
};