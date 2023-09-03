class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for(int i = low; i <= high; i++) 
        {
            string s = to_string(i);
            int n = s.size();
            if(n % 2 == 0) 
            {
                int sum1 = 0;
                int sum2 = 0;
                for (int j= 0; j < n / 2; j++) 
                {
                    sum1+=s[j]-'0';
                    sum2+=s[n-1-j]-'0';
                }
                if(sum1==sum2) count++;
            }
        }
        return count;
    }

};