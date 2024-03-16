class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int>m;
        int n=nums.size();
        int c=0;
        int ans=0;
        //m[0]=0;
        for(int i=0;i<n;i++)
        {
            c+=(nums[i]==0)?-1:1;
            if(c==0) ans=max(ans,i+1);
            if(!m.count(c))m[c]=i;
            else ans=max(ans,i-m[c]);
        }
        return ans;
    }
    
};
// [0,0,1,0,1,0,0,1,0,1,1]
  //0 0 1 1 2 2 2 3 3 4 5