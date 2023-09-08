class Solution {
public:
    int findLucky(vector<int>& arr) {
        priority_queue<int>pq;
        unordered_map<int,int>m;
        for(int i=0;i<arr.size();i++)
        {
            m[arr[i]]++;
        }
        for(auto i:m)
        {
            if(i.second==i.first) pq.push(i.first);
        }
        if(pq.empty()) return -1;
        else return pq.top();
    }
};