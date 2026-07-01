class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1;
        int pivot_idx = right + 1;
        while(pivot_idx != k-1){
            pivot_idx = partition(nums,left,right);
            if(pivot_idx < k-1){
                left = pivot_idx + 1;
            }else{
                right = pivot_idx - 1;
            }
        }
        return nums[pivot_idx];
    }

    int partition(std::vector<int>& nums, int left, int right){
        int random_idx = left + std::rand() % (right - left + 1);
        std::swap(nums[random_idx],nums[right]);

        int pivot_idx = right;
        int p = left;

        for(int i = left; i < right; i++){
            if(nums[i] >= nums[pivot_idx]){
                std::swap(nums[p],nums[i]);
                p++;
            }
        }

        std::swap(nums[p],nums[right]);
        return p;
    }
};
