class MedianFinder {
private:
    priority_queue<int> maxheap;
    priority_queue<int,vector<int>,greater<int>> minheap;
public:
    MedianFinder() {}
    
    void addNum(int num) {
        if(minheap.empty()){
            minheap.emplace(num);
            return;
        }
        int minleft = minheap.top();
        if(num > minleft){
            minheap.emplace(num);
            if(minheap.size() > maxheap.size() + 1){
                maxheap.emplace(minheap.top());
                minheap.pop();
            }
            return;
        }
        maxheap.emplace(num);
        if(maxheap.size() > minheap.size() + 1){
            minheap.emplace(maxheap.top());
            maxheap.pop();
        }
        return;
    }
    
    double findMedian() {
        if(maxheap.size() == minheap.size()) return (maxheap.top() + minheap.top()) / 2.0;
        if(maxheap.size() > minheap.size()) return maxheap.top();
        return minheap.top();
    }
};
