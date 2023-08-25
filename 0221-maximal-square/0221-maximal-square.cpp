class Solution {
public:
    //similar to leetcode 85
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> heights(cols, 0);
        int maxSquareSide = 0;
        for(int i = 0; i < rows; i++) 
        {
            for(int j = 0; j < cols; j++) 
            {
                if (matrix[i][j] == '1') 
                {
                    heights[j]++;
                }   
                else 
                {
                    heights[j] = 0;
                }
            }
            maxSquareSide = max(maxSquareSide, largestSquareSide(heights));
        }
        return maxSquareSide * maxSquareSide; // Return area of largest square
    }

    int largestSquareSide(vector<int>& heights) {
        stack<int> st;
        int maxSide = 0;
        int n = heights.size();
        for (int i = 0; i <= n; i++) 
        {
            while (!st.empty() && (i==n || heights[i] < heights[st.top()])) 
            {
                int height = heights[st.top()];
                st.pop();
                int width;
                if(st.empty()) 
                {
                    width = i;
                }
                else 
                {
                    width = i - st.top() - 1;
                }
                maxSide = max(maxSide, min(width, height)); // Update maximum square side length // square's side length is limited by its shorter dimension to maintain its square shape.
            }
            st.push(i);
        }  
        return maxSide;
    }
};