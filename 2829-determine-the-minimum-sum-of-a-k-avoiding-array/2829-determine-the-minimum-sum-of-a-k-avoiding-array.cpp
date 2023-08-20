class Solution {
public:
    int minimumSum(int n, int k) {
        set<int>s;
        int sum=0;
        int num=1;
        while(s.size()<n)
        {
            if(!(s.count(k-num)>0)) //if complement not present
            {
                s.insert(num);
                sum+=num;
            }
            num++;
        }
        return sum;
    }
};
