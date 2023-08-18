class MedianFinder {
public:

    priority_queue<int>maxheap; // left half 
    priority_queue<int,vector<int>,greater<int>>minheap; // right half
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxheap.empty() || num<=maxheap.top()) //push in left half
            maxheap.push(num);
        else  //push in right half
            minheap.push(num);

        //tree left side titled,balance it
        if(maxheap.size()>minheap.size()+1)
        {
            minheap.push(maxheap.top());
            maxheap.pop();
        }
        //tree right side titled,balance it
        else if(minheap.size()>maxheap.size()+1)
        {
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }
    
    double findMedian() {
        if(minheap.size()==maxheap.size())
        {
            return ((minheap.top()+maxheap.top())/2.0);
        }
        else if(maxheap.size()>minheap.size())
        {
            return maxheap.top();
        }
        else
            return minheap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */