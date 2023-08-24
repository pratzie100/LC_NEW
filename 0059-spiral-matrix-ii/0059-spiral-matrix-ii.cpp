class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<int>nums;
        for(int i=1;i<=n*n;i++)
        {
            nums.push_back(i);
        }
        vector<vector<int>>ans(n,vector<int>(n,0));
        int count=0;
        int left=0,right=n-1,top=0,bottom=n-1;
        int dir=1;
        while(left<=right && top<=bottom)
        {
            if(dir==1)
            {
                for(int i=left;i<=right;i++)
                {
                    ans[top][i]=nums[count++];
                }
                top++;
                dir=2;
            }
            else if(dir==2)
            {
                for(int i=top;i<=bottom;i++)
                {
                    ans[i][right]=nums[count++];
                }
                right--;
                dir=3;
            }
            else if(dir==3)
            {
                for(int i=right;i>=left;i--)
                {
                    ans[bottom][i]=nums[count++];
                }
                bottom--;
                dir=4;
            }
            else if(dir==4)
            {
                for(int i=bottom;i>=top;i--)
                {
                    ans[i][left]=nums[count++];
                }
                left++;
                dir=1;
            }
        }
        return ans;
    }
};