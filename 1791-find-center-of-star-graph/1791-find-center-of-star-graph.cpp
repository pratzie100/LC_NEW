class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_multiset<int>ms;
        for(int i=0;i<edges.size();i++){
            ms.insert(edges[i][0]);
            ms.insert(edges[i][1]);
        }
        for(auto i:ms){
            if(ms.count(i)==edges.size()) return i;
        }
        return -1;
    }
};