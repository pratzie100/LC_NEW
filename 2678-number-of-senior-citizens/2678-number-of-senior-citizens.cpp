class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count=0;
        for(string s:details)
        {
            string age="";
            age+=s[11];
            age+=s[12];
            cout<<age<<" "<<endl;
            int ag=stoi(age);
            if(ag>60) count++;
        }
        return count;
    }
};