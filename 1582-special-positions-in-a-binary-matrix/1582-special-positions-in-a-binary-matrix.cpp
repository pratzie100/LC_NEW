class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<int>row(m,0);
        vector<int>col(n,0);
        for(int i=0;i<m;i++)
        {
            int sum=0;
            for(int j=0;j<n;j++)
            {
                sum+=mat[i][j];
            }
            row[i]=sum;
        }
        for(int j=0;j<n;j++)
        {
            int s=0;
            for(int i=0;i<m;i++)
            {
                s+=mat[i][j];
            }
            col[j]=s;
        }
        int c=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==1)
                {
                  if(row[i]==1 && col[j]==1)   c++;
                }
            }
        }
        return c;
    }
};
