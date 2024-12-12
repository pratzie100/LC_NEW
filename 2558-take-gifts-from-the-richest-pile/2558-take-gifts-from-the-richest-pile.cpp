class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long ans=0;
        multiset<int>s(begin(gifts),end(gifts));
        while(k--){
            auto it=s.rbegin();
            int x=*it;
            s.erase(s.find(x));
            s.insert(floor(sqrt(x)));
        }
        for(int i:s){
            ans+=i;
        }
        return ans;
    }
};