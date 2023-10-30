class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(begin(arr),end(arr),[&](int a,int b){
            int x=__builtin_popcount(a);
            int y=__builtin_popcount(b);
            if(x==y) return a<b;
            return x<y;
        });
        return arr;
    }
};