#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<pair<double, pair<int, int>>>> pq;
        int n = arr.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                double fraction = (double)arr[i] / arr[j];
                pq.push({fraction, {arr[i], arr[j]}});
            }
        }
        while (!pq.empty() && k > 1) {
            pq.pop();
            k--;
        }
        pair<int, int> result = pq.top().second;
        return {result.first, result.second};
    }
};
