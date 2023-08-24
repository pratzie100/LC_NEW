class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth) {
        vector<string>justifiedText;  // To store the final justified lines
        vector<string>currentLine;    // To store words of the current line being processed
        int lineWordLength = 0;        // To track the total length of words in the current line
        
        for (string word : words) 
        {
            if(word.size()+currentLine.size()+lineWordLength > maxWidth) 
            {
                for (int i = 0; i < maxWidth - lineWordLength; i++) 
                {
                    currentLine[i % (currentLine.size() - 1 ? currentLine.size() - 1 : 1)] += ' ';
                }
                justifiedText.push_back("");
                for (string s : currentLine) justifiedText.back() += s;
                currentLine.clear();
                lineWordLength = 0;
            }
            currentLine.push_back(word);
            lineWordLength += word.size();
        }
        
        string lastLine = "";
        for (string s : currentLine) lastLine += s + ' ';
        lastLine = lastLine.substr(0, lastLine.size() - 1);  // remove trailing space
        while (lastLine.size() < maxWidth) lastLine += ' ';
        justifiedText.push_back(lastLine);
        
        return justifiedText;
    }
};
