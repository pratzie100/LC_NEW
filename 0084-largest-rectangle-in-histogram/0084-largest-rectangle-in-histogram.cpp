class Solution {
public:
    int largestRectangleArea(vector<int>& histo) {
        stack<int>st; //stack stores indices of the bars in ascending order of heights.
        int maxA = 0;
        int n=histo.size();
        //For each histogram bar, we compare its height with the height of the bar at the top of the stack.
// If the current bar's height is greater than or equal to the height of the bar at the top of the stack, we simply push the current index onto the stack.
// If the current bar's height is smaller than the height of the bar at the top of the stack, it means we can calculate the area of rectangles that end at the current index. We pop the index from the stack and calculate the width as the difference between the current index and the index at the top of the stack. The height of the rectangle is the height of the bar that was at the top of the stack. We continue this process until we find a bar with a smaller height or the stack becomes empty.
// After processing all bars, there might be remaining bars in the stack. These bars can be used to calculate the area of rectangles that extend until the end of the histogram.
// The maximum area encountered during this process is the area of the largest rectangle in the histogram.
        for(int i = 0; i <= n; i++) 
        {
            while(!st.empty() && (i==n || histo[i] < histo[st.top()])) 
            {
                int height = histo[st.top()];
                st.pop();
                int width;
                if(st.empty())
                    width = i;
                else
                    width = i - st.top() - 1;
                maxA = max(maxA, width * height);
            }
            st.push(i);
        }
        return maxA;
    }
};