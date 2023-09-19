class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // while(nums[0]!=nums[nums[0]])
        // {
        //     swap(nums[0],nums[nums[0]]);
        // }
        // return nums[0];
        
        // map<int,int>m;
        // for(int i=0;i<nums.size();i++)
        // {
        //     m[nums[i]]++;
        // }
        // for(auto i:m)
        // {
        //     if(i.second>1) return i.first;
        // }
        // return -1;
        
        int low = 1, high = nums.size() - 1;
        
        while (low < high) 
        {
            int mid = (low + high) / 2;
            int count = 0;
            
            for (int num : nums) 
            {
                if (num <= mid) 
                    count++;
            }
            if (count > mid) 
            {
                high = mid;
            } 
            else 
            {
                low = mid + 1;
            }
        }
        return low;
    }
};