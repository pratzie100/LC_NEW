class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char>st(begin(allowed),end(allowed));
        int k=0;
        for(string i:words){
            int n=i.size();
            int j=0;
            for(char c:i){
                if(st.count(c))j++;
            }
            if(j==n) k++;
        }
        return k;
    }
};