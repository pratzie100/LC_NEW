class Solution {
public:
    int minimumLength(string s) {
        int n=s.size();
        int answer=n;
        unordered_map<char,int>m;
        for(char c:s){
            m[c]++;
            if(m[c]>=3){
                m[c]=1;
                answer-=2;
            }
        }
        return answer;
    }
};