class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        set<int>s(begin(arr),end(arr));
        int c=0;
        for(int i=1;;i++)
        {
            if(s.find(i)==end(s))
            {
                c++;
                if(c==k) return i;
            }
        }
    }
};