class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_multiset<int>ms;
        for(int i:arr) ms.insert(i);
        sort(begin(arr),end(arr),[&](int &a,int &b){
            if(ms.count(a)==ms.count(b)) return a<b;
            return ms.count(a)<ms.count(b);
        });
        unordered_set<int>s(begin(arr)+k,end(arr));
        return s.size();
    }
};