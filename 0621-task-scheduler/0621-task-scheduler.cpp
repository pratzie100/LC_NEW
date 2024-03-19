class Solution {
public:
    int leastInterval(vector<char>& t, int n) {
        int tot=t.size();
        unordered_map<char,int>m;
        int maxoc=0;
        for(char c:t){m[c]++;maxoc=max(maxoc,m[c]);}
        //int maxoc=0;
        //for(auto i:m)maxoc=max(maxoc,i.second);
        int x=0;
        for(auto i:m){if(i.second==maxoc)x++;}
        return max((maxoc-1)*(n+1)+x,tot);
    }
    //a--a--a
};