class MedianFinder {
public:
    priority_queue<int>maxheap;  // Holds the left half of numbers (lower values)
    priority_queue<int,vector<int>,greater<int>> minheap;  // Holds the right half of numbers (higher values)

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxheap.empty() || num<=maxheap.top()) 
        {
            // If the new number is smaller or equal to the maximum in maxheap, insert into maxheap
            maxheap.push(num);
        } 
        else 
        {
            // Otherwise, insert into minheap
            minheap.push(num);
        }
        // Balance the trees if they become skewed
        if(maxheap.size()>minheap.size()+1) 
        {
            minheap.push(maxheap.top());
            maxheap.pop();
        } 
        else if(minheap.size()>maxheap.size()+1) 
        {
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }
    
    double findMedian() {
        if(minheap.size()==maxheap.size()) 
        {
            // Both heaps have equal size, so the median is the average of their tops
            return (minheap.top()+maxheap.top())/2.0;
        } 
        else if(maxheap.size()>minheap.size()) 
        {
            // maxheap has more elements, so the median is the top of maxheap
            return maxheap.top();
        } 
        else 
        {
            // minheap has more elements, so the median is the top of minheap
            return minheap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */