class Solution {
public:
    int trap(vector<int>& h) {
        int n=h.size();
        vector<int>pref(n);
        vector<int>suff(n);
        pref[0]=h[0];
        suff[n-1]=h[n-1];
        for(int i=1;i<n;i++)
            pref[i]=max(pref[i-1],h[i]);
        for(int i=n-2;i>=0;i--) suff[i]=max(suff[i+1],h[i]);
        int ans=0;
        for(int i=0;i<n;i++) ans+=min(pref[i],suff[i])-h[i];
        return ans;
    }
};