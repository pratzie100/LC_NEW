class Solution {
public:
    int dfs(int n, int k, int rootVal) {
        if (n == 1) {
            return rootVal;
        }

        int totalNodes = pow(2, n - 1);

        // Target node will be present in the right half sub-tree of the current root node.
        if (k > (totalNodes / 2)) {
            int nextRootVal = (rootVal == 0) ? 1 : 0;
            return dfs(n - 1, k - (totalNodes / 2), nextRootVal);
        }
        // Otherwise, the target node is in the left sub-tree of the current root node.
        else {
            int nextRootVal = (rootVal == 0) ? 0 : 1;
            return dfs(n - 1, k, nextRootVal);
        }
    }
    int kthGrammar(int n, int k) {
        // vector<string>v(n);
        // if(n==1) v[0]="0";
        // else
        // {v[0]="0";
        // v[1]="01";}
        // for(int i=2;i<n;i++)
        // {
        //     string res="";
        //     for(int j=0;j<v[i-1].size();j++)
        //     {
        //         if(v[i-1][j]=='0')
        //             res+="01";
        //         else
        //             res+="10";
        //     }
        //     v[i]=res;
        // }
        // return v[n-1][k-1]-48;

          return dfs(n, k, 0);
    }
};