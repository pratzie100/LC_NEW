class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // int t = 0;
        // unordered_set<char> c;
        // int l = 0,r = 0;
        // for(r = 0;r < s.length(); r++){
        //     if( c.count(s[r]) == 0){
        //         c.insert(s[r]);
        //         t = max(t, r-l+1);
        //     }else{
        //         while(c.count(s[r])){
        //             c.erase(s[l]);
        //             l++;
        //         }
        //         c.insert(s[r]);
        //     }
        // }
        // return t;
        unordered_map<int,int>m;
        int l=0,r=0;
        int n=s.size();
        int ans=0;
        while(r<n)
        {
            m[s[r]-'a']++;
            while(m[s[r]-'a']>1)
            {
                m[s[l]-'a']--;
                //if(m[s[l]]==0)m.erase(s[l]); not necessary
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};