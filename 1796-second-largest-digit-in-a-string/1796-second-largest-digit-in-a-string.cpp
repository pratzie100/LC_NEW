class Solution {
public:
    int secondHighest(string str) {
        set<int>s;
        for(char c:str)
        {
            if(c>='0' && c<='9')
            {
                s.insert(c-'0');
            }
        }
        if(s.size()<=1) return -1;
        auto it=s.end();
        it--;
        it--;
        return *it;
    }
};