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
        deque<int>d;
        int i=0;
        int j=nums.size()-1;
        while(i<j)
        {
            if(abs(nums[i])>abs(nums[j])){
                d.push_front(nums[i]*nums[i]);
                i++;
            }
            else{
                d.push_front(nums[j]*nums[j]);
                j--;
            }
        }
        d.push_front(nums[i]*nums[i]);
        for(int i:d) cout<<i<<" ";
        vector<int>ans(begin(d),end(d));
        return ans;
    }
};