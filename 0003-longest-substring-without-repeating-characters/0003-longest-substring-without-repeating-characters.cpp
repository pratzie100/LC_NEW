class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        unordered_map<char,int>m;
         int ans=0;
        // for(char &c:s){
        //     m[c]++;
        //     if(m[c]>=2){ 
        //         auto it=m.lower_bound(c);
        //         it->second=(i->second)-1;
        //         it++;

        //     }
          


            
        //     st.insert(c);
        //     int k=st.size();
            
        //     ans=max(ans,k);
        // }

    //  int l=0,r=0;
    //     for(int i=0;i<n;){
            
    //         r=i+1;
    //         while(r<n && s[l]!=s[r]  ){
    //             r++;
    //             ans=max(ans,r-l+1);
    //         }
            
    //         i=l+1;
    //         //abcaz
    //         //abcbz
    //     }


        int l=0,r=0;
        while(r<n){
            // m[s[r]]++;
            auto it=m.find(s[r]);
            if( it !=m.end() && m[s[r]]>=l){
                l=m[s[r]]+1;
               // m.clear();
               m.erase(it);
            }

            
            m[s[r]]=r;
            ans=max(ans,r-l+1);
            r++;
        }

        return ans;
    }
};