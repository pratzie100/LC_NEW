class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int,int>m;
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5) m[bills[i]]++;
            if(bills[i]==10){
                m[bills[i]]++;
                if(!m.count(5)) return false;
                m[5]--;
            }
            if(bills[i]==20){
                m[bills[i]]++;
                if(m[10]>0 && m[5]>0){
                    m[10]--;
                    m[5]--;
                }
                else if(m[5]>=3){
                    m[5]--;
                    m[5]--;
                    m[5]--;
                }
                else return false;
            }
        }
        return true;
    }
};