class Solution {
public:
    int canBeTypedWords(string t, string bl) {
        set<char> s;
        for (int i = 0; i < bl.size(); i++) 
        {
            s.insert(bl[i]);
        }

        int count = 0;
        bool wordBroken = false; // Flag to check if the current word is broken

        for (int i = 0; i < t.size(); i++) 
        {
            if (t[i] != ' ') 
            {
                if (s.count(t[i])) 
                {
                    wordBroken = true;
                }
            } 
            else 
            {
                if (!wordBroken) 
                {
                    count++;
                }
                wordBroken = false; // Reset the flag for the next word
            }
        }

        // Check the last word in the input
        if (!wordBroken) 
        {
            count++;
        }

        return count;
    }
};
