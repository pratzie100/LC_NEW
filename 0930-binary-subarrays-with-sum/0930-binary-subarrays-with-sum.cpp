class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
//         int n=nums.size();
//         int l=0;
//         int r=0;
//         int sum=0;
//         int c=0;
//         while(r<n)
//         {
//              sum=accumulate(begin(nums)+l,begin(nums)+r+1,0LL);
            
//            // sum+=nums[r];
//             // if(sum!=goal)
//             // {
//             //     r++;
//             // }
//             // else
//             // {
//                 while(sum==goal)
//                 {
                    
//                     c++;
//                     sum-=nums[l];
//                     l++;
//                     sum=accumulate(begin(nums)+l,begin(nums)+r+1,0LL);
//                 }
                
//                 r++;
//                 // c++;
//                 // r++;
//                 // sum+=nums[r];
//                 // while(sum==goal)
//                 // {
//                 //     c++;
//                 //     r++;
//                 //     sum+=nums[r];
//                 //     if(sum>goal){sum-=nums[r]; break;}
//                 //     //c++;
//                 // }
//                 // l++;
//             }
//         }
//         return c;
        int n=nums.size();
        unordered_map<int,int>m;
        int count=0;
        int s=0;
        m[0]=1;
        for(int i=0;i<n;i++)
        {
            s+=nums[i];
            count+=m[s-goal];
            m[s]+=1;
        }
        return count;
    }
};