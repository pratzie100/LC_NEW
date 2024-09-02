class Solution {
public:
    #define ll long long
    int chalkReplacer(vector<int>& chalk, int k) {
        int i=0;
        int n=chalk.size();
        if(chalk[i]>k || n==1) return 0; //n==1 for very large k and single student
        ll sum=accumulate(begin(chalk),end(chalk),0ll);
        k=k%sum;
        while(k>=chalk[i]){
            k-=chalk[i];
            i=(++i)%n;
        }
        return i;
    }
};