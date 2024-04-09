class Solution {
public:
    int timeRequiredToBuy(vector<int>& t, int k) {
        deque<int> dq(t.begin(), t.end());
        int sec = 0;
        while (!dq.empty()) {
            int x = dq.front();
            dq.pop_front();
            if (x > 0) {
                x--; 
                sec++; 
                dq.push_back(x); 
            }
            if (x == 0 && k==0) 
                break;
            k = (k + dq.size() - 1) % dq.size(); 
        }
        return sec;
    }
};