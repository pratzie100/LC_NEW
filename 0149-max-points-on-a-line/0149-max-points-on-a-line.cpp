class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans=0;
        int n=points.size();
        for(int i=0;i<n;i++){
            unordered_map<float,int>m; 
            for(int j=i+1;j<n;j++){
                int x1=points[i][0];
                int y1=points[i][1];
                int x2=points[j][0];
                int y2=points[j][1];
                if(x1==x2) m[INT_MAX]++;
                else{
                    float s=(y2-y1)/(1.0*(x2-x1));
                    m[s]++;
                }
            }
            for(auto i:m){
                ans=max(ans,i.second); //stores maximum no of other points that
                //share same slope with points[i].
            }
        }
        return ans+1;//adding 1 to get total max points wiht same slope
    }
};
