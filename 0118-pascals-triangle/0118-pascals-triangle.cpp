class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>>ans;
        for(int row=1;row<=n;row++)
        {
            vector<int>temp;
            int elem=1;//first value in current row, which is always 1 in Pascal's Triangle.
            for(int col=1;col<=row;col++)
            {
                temp.push_back(elem);
                elem=elem*(row-col);
                elem/=col;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};