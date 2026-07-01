class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue<int> min_heap;

        for(const int num : nums){
            min_heap.emplace(-1 * num);
            if(min_heap.size() > k){
                min_heap.pop();
            }
        }
        return -1 * min_heap.top();
    }
};
