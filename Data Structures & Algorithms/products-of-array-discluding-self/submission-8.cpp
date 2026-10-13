class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(),1);

        int leftpru = 1;
        for(int i = 0; i < nums.size(); i++){
            res[i] *= leftpru;
            leftpru *= nums[i];
        }
        int rightpru = 1;
        for(int i = nums.size() - 1; i >=0 ; i--){
            res[i] *= rightpru;
            rightpru *= nums[i];
        }

        return res;
    }
};
