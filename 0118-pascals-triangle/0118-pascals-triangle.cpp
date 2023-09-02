class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>>ans;
        vector<int>temp;
        for(int row=1;row<=n;row++)
        {
            temp.clear();
            int a=1;
            for(int i=1;i<=row;i++)
            {
                temp.push_back(a);
                a=a*(row-i)/i;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};