class Solution {
public:
    vector<int> lastVisitedIntegers(vector<string>& words) {
        vector<int> result;
        int currentIndex;
        int n = words.size();
        vector<int> temporaryStack;
        for(int i = 0; i < n; i++) 
        {
            if(words[i]!="prev") 
            {
                temporaryStack.push_back(stoi(words[i]));
                currentIndex = temporaryStack.size() - 1;
            } 
            else 
            {
                if (temporaryStack.empty() || currentIndex < 0) 
                {
                    result.push_back(-1);
                } 
                else 
                {
                    result.push_back(temporaryStack[currentIndex]);
                    currentIndex--;
                }
            }
        }
        return result;
    }
};