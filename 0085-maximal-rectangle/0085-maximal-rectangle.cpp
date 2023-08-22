class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> heights(cols, 0);
        int maxArea = 0;
        
        for(int i=0;i<rows;i++) 
        {
            // Updating heights array based on current row
            for(int j=0;j<cols;j++) 
            {
                if (matrix[i][j]=='1')
                    heights[j]++;
                else
                    heights[j] = 0;
            }
            // Calculate largest rectangle for current row 
            maxArea = max(maxArea, largestRectangleArea(heights));
        }
        return maxArea;
    }
    
    //apply leetcode 84
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        int n = heights.size();
        
        for (int i=0;i<=n;i++) 
        {
            while (!st.empty() && (i==n||heights[i]<heights[st.top()])) 
            {
                int height = heights[st.top()];
                st.pop();
                int width;
                if (st.empty())
                    width=i;
                else
                    width=i-st.top()-1;
                maxArea = max(maxArea, width*height);
            }
            st.push(i);
        }
        return maxArea;
    }
};
