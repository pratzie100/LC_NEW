class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        int x=*max_element(begin(arr),end(arr));
        if(x==arr[0] || x==arr[1]) return x;
        int current_winner = arr[0];
        int win_count = 0;

        for (int i = 1; i < n; i++) {
            if (arr[i] > current_winner) {
                current_winner = arr[i];
                win_count = 1;
            } else {
                win_count++;
            }

            if (win_count == k) return current_winner;
        }

        return current_winner;
    }
};
