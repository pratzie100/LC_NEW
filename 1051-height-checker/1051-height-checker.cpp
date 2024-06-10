class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int>v(begin(heights),end(heights));
        sort(begin(v),end(v));
        int c=0;
        for(int i=0;i<heights.size();i++){
            if(heights[i]!=v[i]) c++;
        }
        return c;
    }
};