class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        multiset<int>s(begin(nums)+1,end(nums)); 
        int first=nums[0]; 
        long long ans=0; 
        for(int j=1;j<n-1;j++)
        {  
            s.erase(s.find(nums[j]));
            int last=(*(--s.end()));
            long long val=(long long)(first-nums[j])*last;
            ans=max(ans,val);  
            first=max(first,nums[j]);
        } 
        return ans;
        
        
//         int n=nums.size();
//         vector<int>p(n);
//         p[0]=nums[0];
//         for(int i=1;i<n;i++) p[i]=max(p[i-1],nums[i]);

//         vector<int>s(n);
//         s[n-1]=nums[n-1];
//         for(int i=n-2;i>=0;i--) s[i]=max(s[i+1],nums[i]);

//         long long ans=0;
//         for (int i=1;i<n-1;i++) 
//         {
//             long long val=(long long)(p[i-1]-nums[i])*s[i+1]; 
//             ans=max(ans,val);
//         }
//         if(ans<0) return 0;
//         return ans;
        

    }
};
