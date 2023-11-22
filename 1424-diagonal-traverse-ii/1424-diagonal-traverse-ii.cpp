class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        // Step 1: Find the dimensions of the matrix (m x n)
int m = nums.size(), n = 0;

    // Find the maximum size among the inner vectors to get the number of columns (n)
    for (int i = 0; i < m; i++) {
        if (n < nums[i].size())
            n = nums[i].size();
    }

    // Step 2: Create a temporary matrix (temp) to store elements diagonally
    vector<vector<int>> temp(m + n);

    // Step 3: Fill the temporary matrix by converting the input matrix into an adjacency list
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < nums[i].size(); j++) {
            temp[i + j].push_back(nums[i][j]);
        }
    }

    // Step 4: Reverse the order of elements in each row of the temporary matrix
    for (int i = 0; i < m + n; i++) {
        reverse(temp[i].begin(), temp[i].end());
    }

    // Step 5: Flatten the temporary matrix and store the result in the 'ans' vector
    vector<int> ans;

    for (int i = 0; i < m + n; i++) {
        for (int j = 0; j < temp[i].size(); j++) {
            ans.push_back(temp[i][j]);
        }
    }

    // Step 6: Return the final result
    return ans;
        
    }
};