class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int l=INT_MIN;
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[i].size();j++)
            {
                if(mat[i][j]>l)
                    l=mat[i][j];
            }
        }
        // vector<int>ans;
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[i].size();j++)
            {
                 if(mat[i][j]==l)
                {
                    // ans.push_back(i);
                    // ans.push_back(j);
                    // goto end;
                    return {i,j};
                }
            }
        }
        return {};
    }
};