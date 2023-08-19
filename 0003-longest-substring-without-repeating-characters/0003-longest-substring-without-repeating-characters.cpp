class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //abca //abcababcdc //acdebfbabcdc //acbdefbabcdc //abba
        unordered_map<char,int>m;
        int left=0,right=0,res=0;
        for(int right=0;right<s.size();right++)
        {
            if(m[s[right]]>0) //if s[right] already exist in map
                left=max(left,m[s[right]]); //update left pointer //here we will not do left=m[s[right]] as left should always move forward..there will
            //be chance that s[right] previously occured way before where left is present currently,in that case left=m[s[right]] will shift left 
            //pointer backwards leading to wrong current window size calculation at res(3rd line) ..ex- abba 
            
            m[s[right]]=right+1;  // update length of max substring ending at right pointer
            
            res=max(res,m[s[right]]-left);  //m[s[right]]-left is current substring window size..ex //acdebfbabcdc when right reaches second 'b' ,then 
            //res=max(6,7-5)=6 //note at this line res already has length of max required substring before current iteration
        }
        return res;

    }
};
