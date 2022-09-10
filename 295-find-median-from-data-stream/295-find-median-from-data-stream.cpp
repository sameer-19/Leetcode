class MedianFinder
{
    priority_queue<int> maxHeap; // for storing the left side smaller elements
    priority_queue<int, vector < int>, greater < int>> minHeap; // for larger elements
    public:

        MedianFinder() {}

    void addNum(int num)
    {
        if (maxHeap.empty() || maxHeap.top() >= num) maxHeap.push(num);
        else minHeap.push(num);

        if (maxHeap.size() > minHeap.size() + 1)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if (maxHeap.size() + 1 < minHeap.size())
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian()
    {
        if (minHeap.size() == maxHeap.size())
            return minHeap.empty() ? 0 : (double)(minHeap.top() + maxHeap.top()) / 2.0;

        return minHeap.size() > maxHeap.size() ? minHeap.top() : maxHeap.top();
    }
};

/**
 *Your MedianFinder object will be instantiated and called as such:
 *MedianFinder* obj = new MedianFinder();
 *obj->addNum(num);
 *double param_2 = obj->findMedian();
 */