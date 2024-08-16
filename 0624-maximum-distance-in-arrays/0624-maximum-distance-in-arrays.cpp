class Solution {
public:
    //intuitive answer is simple: abs diff btw minimum of all first elements
    //(top of minheap) and maximum of all last elements(top of maxheap). 
    //BUT only problem will be when 
    //both belong to same vector. Then we may think of removing Greater one
    // from maxheap and finding difference between smallest from min heap 
    //and next smaller greater one from maxheap,
    //Ex- [1,5],[2,4]= abs(1-4)=3
    //but this may fail when elements are negative
    //Ex- [1,5],[-2]= abs(1-(-2))=3 (not correct answer)
    //Ex- [1,5],[-2]= max({abs(1-(-2)), abs(5-(-2))})=7 will give correct ans
    //ie, store both tops from both heap , and then calculate effect of 
    // removal individually one by one(ie,remove min heap top, then check effect, 
    //& remove maxheap top, then check effect) and maxm of both effects will be 
    //answer
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