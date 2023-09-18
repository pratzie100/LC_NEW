class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n=spells.size();
        int m=potions.size();
        vector<int>pairs(n);
        sort(begin(potions),end(potions));
        for(int i=0;i<spells.size();i++)
        {
            int low=0;
            int high=m-1;
            while(low<=high)
            {
                int mid=low+(high-low)/2;
                if((long long)spells[i]*potions[mid]>=success)
                {
                    high=mid-1;
                }
                else
                {
                    low=mid+1;
                }
            }
            pairs[i]=m-low;
        }
        return pairs;
    }
};