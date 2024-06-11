class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int>ans;
        unordered_map<int,int>mp;
        for(int i:arr1)mp[i]++;
        for(int i=0;i<arr2.size();i++){
            int x=mp[arr2[i]];
            while(x--){
                ans.push_back(arr2[i]);
            }
        }
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<arr1.size();i++){
            if(!count(begin(arr2),end(arr2),arr1[i]))pq.push(arr1[i]);
        }
        while(!pq.empty()){
            ans.push_back(pq.top());pq.pop();
        }
        return ans;
    }
};