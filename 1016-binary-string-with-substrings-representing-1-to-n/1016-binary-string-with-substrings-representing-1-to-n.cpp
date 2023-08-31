class Solution {
public:
    bool queryString(string s, int n) {
        for(int i=1;i<=n;i++)
        {
            int num=i;
            string subs="";
            while(num>0)
            {
                subs=to_string(num&1)+subs; //num&1 is lsb of current num
                num>>=1;
            }
            auto it=s.find(subs);
            if(it==string::npos) return false;
        }
        return true;
    }
};