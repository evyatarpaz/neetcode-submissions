class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for(int i = 1; i < 33; i++){
            res = (res << 1) | (n&1);
            n >>= 1;
        }
        return res;

    }
};
