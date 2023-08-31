class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int>maxrange(n+1,0);
        for(int i=0;i<ranges.size();i++)
        {
            int start=max(0,i-ranges[i]);            
            int end=min(n,i+ranges[i]);
            maxrange[start]=max(maxrange[start],end);            
        }
        int taps=0,currentEnd=0,nextEnd=0;
        for(int i=0;i<=n;i++)
        {
            if(i>nextEnd) return -1;
            if(i>currentEnd)
            {
                taps++;
                currentEnd=nextEnd;
            }
            nextEnd=max(nextEnd,maxrange[i]);
        }
        return taps;
    }
};