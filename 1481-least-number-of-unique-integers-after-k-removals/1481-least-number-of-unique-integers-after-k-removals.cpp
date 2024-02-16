class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int>m;
        for(int i:arr) m[i]++;
        sort(begin(arr),end(arr),[&](int &a,int &b){
            if(m[a]==m[b]) return a<b;
            return m[a]<m[b];
        });
        unordered_set<int>s(begin(arr)+k,end(arr));
        return s.size();
    }
};