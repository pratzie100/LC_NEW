class Solution {
public:
    int countStudents(vector<int>& stud, vector<int>& sand) {
        deque<int>dq;
        for(int i=0;i<stud.size();i++)
        {
            dq.push_back(stud[i]);
        }
        stack<int>st;
        int n=sand.size();
        for(int i=n-1;i>=0;i--)
        {
            st.push(sand[i]);
        }
        // while(1)
        // {
            //bool alldone=0;
            int k=0;
            while(k<dq.size())
            {
                if(dq.front()==st.top()) {k=0;st.pop();dq.pop_front(); if(dq.empty())return 0;}
                else
                {
                    int x=dq.front();
                    dq.pop_front();
                    dq.push_back(x);
                    k++;
                }
            }
            return k;
            
       // }
    }
};