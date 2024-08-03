class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int>m;
        for(int i:arr) m[i]++;
         for(int i:target) {
             if(!m.count(i)) {return false;}
             m[i]--;
             if(m[i]==0) m.erase(i);
         }
        return m.empty()? true:false;
    }
};