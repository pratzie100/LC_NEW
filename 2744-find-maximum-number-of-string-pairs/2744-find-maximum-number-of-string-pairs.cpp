class Solution {
public:
    static string reverses(string s)
    {
        reverse(s.begin(),s.end());
        return s;
    }
    int maximumNumberOfStringPairs(vector<string>& words) {
        int count=0;
        for(int i=0;i<words.size()-1;i++)
        {
            for(int j=i+1;j<words.size();j++)
            {
                string ss=reverses(words[j]);
                if(words[i]==ss)
                    count++;
            }
        }
        return count;
    }
};