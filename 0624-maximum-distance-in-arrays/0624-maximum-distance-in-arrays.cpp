class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        priority_queue<pair<int,int>>pqmax;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pqmin;
        for(int i=0;i<arrays.size();i++){
            pqmin.push({arrays[i][0],i});
            pqmax.push({arrays[i][arrays[i].size()-1],i});
        }
        int x,y;
        if(pqmin.top().second==pqmax.top().second){
            x=pqmax.top().first;
            pqmax.pop();
            y=pqmin.top().first;
            pqmin.pop();
            return max({abs(x-pqmin.top().first),abs(y-pqmax.top().first)});
        }
        return abs(pqmin.top().first-pqmax.top().first);

        
    }
};