class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // if(binary_search(nums.begin(),nums.end(),target))  
        // {
        //     //finding smallest index with value>=target
        // int st=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        //     //finding smallest index with value>target using upper bound and subtracting 1 from it will ofcourse be target itself
        // int en=upper_bound(nums.begin(),nums.end(),target)-nums.begin()-1;
        // return {st,en};
        // }
        // else return{-1,-1};

        //more better
        int st=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        if(st==nums.size() || nums[st]!=target) return{-1,-1};
        int en=upper_bound(nums.begin(),nums.end(),target)-nums.begin()-1;
        return {st,en};

        // int start=0;
        // int end=nums.size()-1;
        // int res=-1;
        // while(start<=end)
        // {
        //     int mid=start+(end-start)/2;
        //     if(target==nums[mid])
        //     {
        //         res=mid; //possible answer
        //         end=mid-1; //search in left part
        //     }
        //     else if(target>nums[mid])
        //     {
        //         start=mid+1;
        //     }
        //     else
        //     {
        //         end=mid-1;
        //     }
        // }
        // start=0;
        // end=nums.size()-1;
        // int ress=-1;
        // while(start<=end)
        // {
        //     int mid=start+(end-start)/2;
        //     if(target==nums[mid])
        //     {
        //         ress=mi d; //possible answer
        //         start=mid+1; //search in right part 
        //     }
        //     else if(target>nums[mid])
        //     {
        //         start=mid+1;
        //     }
        //     else
        //     {
        //         end=mid-1;
        //     }
        // }
        // return {res,ress};

        
       
        //O(N)
        // int founds=-1;
        // int founde=-1;
        // for(int i=0;i<nums.size();i++)
        // {
        //     if(nums[i]==target)
        //     {
        //         founds=i;
        //         break;
        //     }
        // }
        // for(int i=nums.size()-1;i>=0;i--)
        // {
        //     if(nums[i]==target)
        //     {
        //         founde=i;
        //         break;
        //     }
        // }
        // vector<int> ans;
        // ans.push_back(founds);
        // ans.push_back(founde);
        // return ans;
    }
};