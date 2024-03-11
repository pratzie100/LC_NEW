class Solution {
public:
//kqep //pekeq //kqeep
    string customSortString(string order, string s) {
        int i=0;
        int n=s.size();
        // unordered_map<char,int>m;
        // for(int i=0;i<order.size();i++)
        // {
        //     m[order[i]]=i;
        // }
       // unordered_set<char>S(begin(order),end(order));
        unordered_multiset<char>ms(begin(s),end(s));
        //int e=order.size();
        string ans="";
      //string add="";
        for(int j=0;j<order.size();j++)
        {
            if(ms.count(order[j]))
            {
                int y=ms.count(order[j]);
                string x(y,order[j]);
                ans+=x;
            }
            // if(S.count(s[j]))
            // {
            //     int y=ms.count(s[j]);
            //     string x(y,s[j]);
            //     ans+
            // }
             // if(m.count(s[j]))
            // {
            //     ans[m[s[j]]]=s[j];
            //     int x=0;
            //     for(char c: ans)
            //     {
            //         if(c=='A') x++;
            //     }
            //     if(x==0) break;
            // }
           // else add.push_back(s[j]);
        }
        for(int j=0;j<s.size();j++)
        {
            if(order.find(s.substr(j,1))==string::npos)
           // if(!S.count(s[j]))
                ans+=s[j];
        }
        // cout<<add<<" "<<ans;
        // ans+=add;
        return ans;
        
        
            
    }
};