class Solution {
public:
    typedef long long ll;
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if(sx==fx && sy==fy) return t!=1; //not allowed to be at same cell after a second 
        ll xdiff=abs(sx-fx);
        ll ydiff=abs(sy-fy);
        ll maxdist=max(xdiff,ydiff);
        if(maxdist<=t) return true;
        return false;
    }
};