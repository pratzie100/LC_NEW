class Solution {
public:
    int totalMoney(int n) {
        int sum=0;
        int c=1;
        int z;
        for(int i=1;i<=n;i++)
        {
            if((i-1)%7==0)
            {
                
                sum+=c;
                z=c+1;
                c++;
                
                cout<<sum<<" "<<z<<endl;
            }
            else
            {
                sum+=z;
                z++;
                cout<<sum<<" "<<z<<endl;
            }
        }
        return sum;
    }
};
// 1 2 3 4 5 6 7 1 2 3 4 5 6 7 1 2 3 4 5 6 7
// m t w t f s s m t w t f s s m t w t f s s   

// m 1 8 15