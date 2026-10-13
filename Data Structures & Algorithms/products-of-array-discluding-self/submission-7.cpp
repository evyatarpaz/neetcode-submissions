class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n+1,1);
        vector<int> suf(n+1,1);
        vector<int> res(n,0);
        for(int i = 0; i < n; i++){
            pre[i+1] = nums[i] * pre[i];
            suf[n - 1 - i] = nums[n-1-i] * suf[n-i];
        }

        for(int i = 0; i < n; i++){
            res[i] = pre[i] * suf[i+1];
        }
        return res;
    }
};

/*

[1,2,4,6] -> [48,24,12,8]
prefix pru -> [1,1,2,8,48]
sufix pru -> [48,48,24,6,1]


*/ 
