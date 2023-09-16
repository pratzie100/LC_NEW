class Solution {
public:

    // Function to check and expand a palindrome around the center
    int check(string s, int l, int r)
    {
        while (l >= 0 and r < s.length() and s[l] == s[r])
        {
            l--;    // Move the left pointer to the left
            r++;    // Move the right pointer to the right
        }
        return r - l - 1;   // Return the length of the palindrome found
    }
    // Main function to find the longest palindromic substring
    string longestPalindrome(string s) {
        int ans = 0, st = 0;   // ans will store the length of longest palindrome found, and st will store starting index of longest palindrome.
        int n = s.length();    
        for (int i = 0; i < n; i++)
        {
            // Calculate the length of palindromes with i as center (odd length) and i, i+1 as center (even length)
            int len1 = check(s, i, i);
            int len2 = check(s, i, i + 1);
            // Calculate the maximum of the two palindrome lengths
            int len = max(len1, len2);
            // If current palindrome length is greater than previous maximum
            if (len > ans)
            {
                ans = len;    // Update the maximum length
                // Calculate starting index of longest palindrome using formula
                st = i - (len - 1) / 2;
            }
        }
        // Return longest palindromic substring using starting index and length
        return s.substr(st, ans);
    }

    // string longestPalindrome(string s) {
    //     //Because problem wants longest palindrome, we can start by checking  longest substrings and iterate toward the shorter-length substrings. First time we find palindrome substring, it is answer
    //     int n=s.size();
    //     for(int len = n; len>0; len--)  //size decreases from n to 1
    //     {
    //         for(int start=0; start<n-len+1; start++) //start pos index from 0 to n-1
    //         {
    //             if(palin(start,start+len,s)) 
    //             {
    //                 return s.substr(start,len);
    //             }
    //         }
    //     }
    //     return "";
    // }

    // bool palin(int i, int j, string& s) {
    //     int left = i;
    //     int right = j-1;
    //     while(left<right) 
    //     {
    //         if(s[left]!=s[right]) return false;
    //         left++;
    //         right--;
    //     }
    //     return true;
    // }

//tle
    // string longestPalindrome(string s) {
    //     int n=s.size();
    //     string ans="";
    //     cout<<s.size()<<ans.size();
    //     for(int i=0;i<n;i++)
    //     {
    //         for(int j=i;j<n;j++)
    //         {
    //             string sub=s.substr(i,j-i+1);
    //             if(palin(sub) && sub.size()>ans.size())
    //             {
    //                 ans=sub;
    //             }
    //         }
    //     }
    //     return ans;
    // }
    // bool palin(string &s){ 
    //     if(s.size()==0) return false;
    //     int i=0;
    //     int j=s.size()-1;
    //     while(i<=j)
    //     {
    //         if(s[i]!=s[j]) return false;
    //         i++;
    //         j--;
    //     }
    //     return true;
    // }
};