class Solution {
public:
    const int N=1000;
    vector<vector<int>>d;
    Solution(){d.resize(N+1);}
    void f()
    {
        for(int  i=1;i<=N;i++)
        {for(int j=i;j<=N;j+=i){
                d[j].push_back(i);     
            }
        }
    }
    int kthFactor(int n, int k) {
        f();
        if(d[n].size()<k) return -1;
        else return d[n][k-1];
    }
};