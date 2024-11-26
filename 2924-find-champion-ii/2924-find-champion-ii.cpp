class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int>indegree(n,0);
        for(auto i:edges){
            indegree[i[1]]++;
        }
        int c=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){c++; ans=i;}
            if(c>1) return -1;
        }
        return ans;
    }
};