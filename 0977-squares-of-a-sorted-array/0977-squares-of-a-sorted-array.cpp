class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // int n=nums.size();
        // vector<int>ans(n,0);
        // for(int i=0;i<n;i++)
        // {
        //     ans[i]=nums[i]*nums[i];
        // }
        // sort(begin(ans),end(ans));
        // return ans;
        
        
        
        // deque<int>d;
        // int i=0;
        // int j=nums.size()-1;
        // while(i<j)
        // {
        //     if(abs(nums[i])>abs(nums[j])){
        //         d.push_front(nums[i]*nums[i]);
        //         i++;
        //     }
        //     else{
        //         d.push_front(nums[j]*nums[j]);
        //         j--;
        //     }
        // }
        // d.push_front(nums[i]*nums[i]);
        // // for(int i:d) cout<<i<<" ";
        // vector<int>ans(begin(d),end(d));
        // return ans;
        
        int n=nums.size();
        vector<int>ans(n);
        int l=0;
        int r=n-1;
        for(int i=n-1;i>=0;i--)
        {
            int g=nums[l]*nums[l];
            int h=nums[r]*nums[r];
            if(g>h){ans[i]=g;l++;}
            else{ans[i]=h;r--;}
        }
        return ans;
    }
};