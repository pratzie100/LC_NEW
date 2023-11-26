class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int c=0;
        int sum=0;
        unordered_multiset<int>s(begin(banned),end(banned));
        for(int i=1;i<=n;i++)
        {
            if(s.find(i)==s.end())
            {
                sum+=i;
                if(sum>maxSum)
                {
                    sum-=i;
                    break;
                }
                c++;
            }
        }
        return c;
    }
};