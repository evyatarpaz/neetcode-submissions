class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        auto comp = [](int val1, int val2){
            return val1 > val2;
        };

        std::nth_element(nums.begin(),nums.begin() + k-1, nums.end(),comp);

        return nums[k-1];
    }
};
