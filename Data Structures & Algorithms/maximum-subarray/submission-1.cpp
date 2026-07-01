class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum_sub = 0;
        int max_sub = nums[0];

        for (int num : nums){
            sum_sub += num;

            max_sub = sum_sub > max_sub ? sum_sub : max_sub;

            sum_sub = sum_sub < 0 ? 0 : sum_sub;

        }
        return max_sub;
    }
};
