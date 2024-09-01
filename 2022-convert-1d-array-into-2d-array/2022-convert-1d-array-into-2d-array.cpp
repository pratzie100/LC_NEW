class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>>ans(m,vector<int>(n));
        int c=0;
        int x=m*n;
        if(x!=original.size()) return {};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                //if(c==original.size()) return {{}};
                ans[i][j]=original[c];
                c++;
            }
        }
        return ans;
    }
};