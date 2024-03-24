class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        unordered_map<int,int>m;
        for(char c:word1)m[c]++;
        for(char c:word2)m[c]--;
        for(auto i:m){if(abs(i.second)>3)return false;}return true;
        // unordered_multiset<char>ms1(begin(word1),end(word1));
        // unordered_multiset<char>ms2(begin(word2),end(word2));
        // for(int i=0;i<26;i++)
        // {
        //     int diff=ms1.count('a'+i)-ms2.count('a'+i);
        //     if(abs(diff)>3) return false;
        // }
        // return true;
    }
};