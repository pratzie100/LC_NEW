class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end()); 
        int boats = 0;
        int left = 0;
        int right = people.size() - 1;
        while (left <= right) {
            if (people[left] + people[right] <= limit) {
                left++;
                right--;
            } else {
                right--;
            }
            boats++; 
        }
        return boats;
    }
};