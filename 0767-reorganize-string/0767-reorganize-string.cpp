class Solution {
public:
    string reorganizeString(string s) {
        /*
Input
"vvvlo"
Output
"lvovv"
Expected
"vlvov"*/
        map<char,int>m;
        for(int i=0;i<s.size();i++)
        {
            m[s[i]]++;
        }
        char maxch='#';
        int maxcnt=0;
        for(auto i:m)
        {
            if(i.second>maxcnt)
            {
                maxcnt=i.second;
                maxch=i.first;
            }
        }
        cout<<maxcnt<<" "<<maxch<<endl;
        if(maxcnt>(s.size()+1)/2) return "";
        string ans(s);
        int ind=0;
        while(m[maxch]!=0)
        {
            ans[ind]=maxch;
            ind+=2;
            m[maxch]--;
        }
        for(auto i:m)
        {
            while(i.second>0)
            {
                if(ind>=s.size()) 
                {    
                    ind=1;
                }
                ans[ind]=i.first;
                ind+=2;
                i.second--;
            }
        }
        return ans;
    }
};