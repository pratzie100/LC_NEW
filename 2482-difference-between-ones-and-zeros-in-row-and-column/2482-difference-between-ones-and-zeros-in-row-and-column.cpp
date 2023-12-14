class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<int>row1(m,0);
        vector<int>row0(m,0);
        vector<int>col1(n,0);
        vector<int>col0(n,0);
        for(int i=0;i<m;i++)
        {
            int zrow=0,orow=0;
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==0) zrow++;
                else orow++;
            }
            row0[i]=zrow;
            row1[i]=orow;
        }
        for(int j=0;j<n;j++)
        {
            int zcol=0,ocol=0;
            for(int i=0;i<m;i++)
            {
                if(mat[i][j]==0) zcol++;
                else ocol++;
            }
            col0[j]=zcol;
            col1[j]=ocol;
        }
        vector<vector<int>>diff(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                diff[i][j]=row1[i]+col1[j]-row0[i]-col0[j];
            }
        }
        return diff;
    }
};