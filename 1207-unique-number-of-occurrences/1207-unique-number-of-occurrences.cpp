class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_set<int>s;
        unordered_map<int,int>m;
        for(int i=0;i<arr.size();i++)
        {
            m[arr[i]]++;
        }
        for(auto i:m)
        {
            s.insert(i.second);
        }
        return s.size()==m.size();    
    }
};