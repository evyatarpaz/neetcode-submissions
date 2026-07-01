class Solution {
public:
    vector<int> countBits(int n) {
        std:vector<int> dp(n+1,0);
        for(size_t i = 1; i < n+1; i++){
            dp[i] = dp[(i & (i-1))] + 1;
        }
        return dp;
    }
};
