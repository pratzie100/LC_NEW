class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int c=0;
        vector<string>ans;
        for(int i=1;i<=n;i++)
        {
            if(c==target.size()) break;
            if(i==target[c])
            {
                c++;
                ans.push_back("Push");
            }
            else
            {
                ans.push_back("Push");
                ans.push_back("Pop");
            }
        }
        return ans;
    }
};
