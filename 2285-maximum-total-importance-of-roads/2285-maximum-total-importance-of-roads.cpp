class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int>v(n);
        for(auto i:roads){
            v[i[0]]++;
            v[i[1]]++;
        }
        vector<pair<int,int>>r;
        for(int i=0;i<n;i++){
            r.push_back(make_pair(v[i],i));
        }
        sort(begin(r),end(r));
        vector<int>imp(n);
        for(int i=0;i<n;i++){
            imp[r[i].second]=i+1;
        }
        long long sum=0;
        for(auto i:roads){
            int x=i[0];
            int y=i[1];
            sum+=imp[x]+imp[y];            
        }
        return sum;
    }
};

// 2 3 4 2 1
// 0 1 2 3 4 
    
// 1 2 2 3 4
// 4 0 3 1 2
    
// 4 3 2 2 1
// 2 1 3 0 4
    
// 4 0 3 1 5
// 1 2 3 4 5
    
    
// 0 1 2 4 3
