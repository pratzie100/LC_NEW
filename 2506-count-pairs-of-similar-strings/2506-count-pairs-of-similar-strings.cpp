class Solution {
public:
    int similarPairs(vector<string>& words) {
        int count=0;
        for(int i=0;i<words.size()-1;i++)
        {
            for(int j=i+1;j<words.size();j++)
            {
                set<char>s1;
                set<char>s2;
                s1.insert(begin(words[i]),end(words[i]));
                s2.insert(begin(words[j]),end(words[j]));
                vector<int>v1(begin(s1),end(s1));
                vector<int>v2(begin(s2),end(s2));
                if(v1==v2) count++;
            }
        }
        return count;
    }
};