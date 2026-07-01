class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0;
        int i = 0;
        for(i ; i < nums.size(); i++){
            res ^= nums[i];
            res ^= i;
            std:cout << nums[i] << i << res << std::endl;
        }
        std::cout << i << std::endl;
        res ^= i;

        return res;
    }
};
