class Solution {
public:
    int pivotInteger(int n) {
        // vector<int>pref(n);
        // vector<int>suff(n);
        // pref[0]=1;
        // suff[n-1]=n;
        // for(int i=1;i<n;i++)
        // {
        //     pref[i]=pref[i-1]+i+1;
        // }
        // for(int i=n-2;i>=0;i--)
        // {
        //     suff[i]=suff[i+1]+i+1;
        // }
        // for(int i=0;i<n;i++)
        // {
        //     if(pref[i]==suff[i])return i+1;
        // }
        // return -1;
        int s=0;
        for(int i=1;i<=n;i++)s+=i;
        for(int i=1;i<=n;i++)
        {
            int x=(i*(i+1))/2;
            int y=s-x+i;
            if(x==y) return i;
        }   
        return -1;
        
    }
};