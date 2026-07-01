class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0;
        int i = 0;
        for(i ; i < nums.size(); i++){
            res ^= nums[i];
            res ^= i;
        }
        res ^= i;

        return res;
    }
};
