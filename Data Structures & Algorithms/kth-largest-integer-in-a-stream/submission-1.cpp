class KthLargest {
private:
    int _k;
    std::priority_queue<int, std::vector<int>, std::greater<int>> _min_heap;
public:
    KthLargest(int k, vector<int>& nums) {
        _k = k;
        for(const int& num : nums){
            add(num);
        }
    }
    
    int add(int val) {
        if(_min_heap.size() < _k){
            _min_heap.push(val);
        }else if(val > _min_heap.top()){
            _min_heap.pop();
            _min_heap.push(val);
        }
        return _min_heap.top();
    }
};
