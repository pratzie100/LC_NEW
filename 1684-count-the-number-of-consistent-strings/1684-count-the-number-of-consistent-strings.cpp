class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        set<char>s(begin(allowed),end(allowed));
        int count=0;
        for(string str:words)
        {
            bool allpresent=true;
            for(char c:str)
            {
                if(!(s.count(c))) allpresent=false; 
            }
            if(allpresent) count++;
        }
        return count;
    }
};