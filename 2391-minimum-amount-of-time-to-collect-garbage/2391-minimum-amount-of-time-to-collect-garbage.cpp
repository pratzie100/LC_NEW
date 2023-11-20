class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int ans = 0;
        int aux_g = 0;
        int aux_p = 0;
        int aux_m = 0;
        int n = garbage.size();
        if(n){
            int g = 0;
            int p = 0;
            int m = 0;
            for(auto i: garbage[0]){
                if(i == 'G'){
                    g++;
                }
                else if(i == 'P'){
                    p++;
                }else{
                    m++;
                }
            }
            ans += g;
            ans += p;
            ans += m;
        }
        for(int i = 1; i<n; ++i){
            int g = 0;
            int p = 0;
            int m = 0;
            for(auto it: garbage[i]){
                if(it == 'G'){
                    g++;
                }
                else if(it == 'P'){
                    p++;
                }else{
                    m++;
                }
            }
            aux_g += travel[i-1];
            aux_p += travel[i-1];
            aux_m += travel[i-1];
            if(g){
                ans += aux_g;
                ans += g;
                aux_g = 0;
            }
            if(p){
                ans += aux_p;
                ans += p;
                aux_p = 0;
            }
            if(m){
                ans += aux_m;
                ans += m;
                aux_m = 0;
            }
        }
        return ans;
    }
};