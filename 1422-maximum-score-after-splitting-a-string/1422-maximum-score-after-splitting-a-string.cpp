class Solution {
public:
    int maxScore(string s) {
        int c=0;
        for(char i:s){
            if(i=='1') c++;
        }
        int z=0;
        int ones=0;
        int ans=INT_MIN;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]=='0') z++;
            else ones++;
            ans=max(ans,z+(c-ones));
        }
        return ans;
    }
};