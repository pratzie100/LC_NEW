class Solution {
public:
    bool areNumbersAscending(string s) {
        vector<int>v;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>='0' && s[i]<='9')
            {
                int j=i;
                string num="";
                while((s[j]>='0' && s[j]<='9'))
                {
                    num+=s[j];
                    j++;
                }
                i+=num.size()-1;
                int numb=stoi(num);
                v.push_back(numb);
            }
        } 
        for(int i:v) cout<<i<<" ";
        if(v.size()==1) return true;
        for(int i=1;i<v.size();i++)
        {
            if(v[i-1]>=v[i]) return false;
        }
        return true;
    }
};