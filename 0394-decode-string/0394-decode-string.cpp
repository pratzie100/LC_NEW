class Solution {
public:
    string decodeString(string s) {
        stack<int> numStack;
        stack<string> strStack;
        string ans = "";
        int n = s.length();
        for(int i = 0; i < n; i++) 
        {
            char c = s[i];
            if(isdigit(c)) 
            {
                int num = c - '0';
                while(i + 1 < n && isdigit(s[i+1])) 
                {
                    num = num * 10 + s[i+1] - '0';
                    i++;
                }
                numStack.push(num);
            }
            else if(c == '[') 
            {
                strStack.push(ans);//represents substring so far
                ans = ""; //empty string to start building new substring
            }
            else if(c == ']') 
            {
                int repeats = numStack.top();
                numStack.pop();
                string temp = strStack.top();
                strStack.pop();
                for(int j = 0; j < repeats; j++) 
                {
                    temp += ans;
                }
                ans = temp;
            }
            else //if aplhabet
            {
                ans += c;
            }
        }
        return ans;
    }
};