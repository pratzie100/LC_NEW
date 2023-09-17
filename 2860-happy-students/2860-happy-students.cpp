
class Solution {
public:
    int countWays(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int happyCount = 0; 
        for(int i=0; i<nums.size(); i++) 
        {
            bool isCurrentStudentHappy = nums[i] < (i+1);
            bool hasNextStudent = (i+1) < nums.size();
            bool isNextStudentHappy = hasNextStudent && nums[i+1] > (i+1);
            if(isCurrentStudentHappy && isNextStudentHappy) 
            {
                happyCount++; 
            } 
            else if(isCurrentStudentHappy && !hasNextStudent) 
            {
                happyCount++; 
            }
        }
        if(nums[0]>0) 
        {
            happyCount++;
        }
        return happyCount; 
    }
};