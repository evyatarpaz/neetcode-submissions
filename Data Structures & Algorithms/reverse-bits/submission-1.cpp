class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for(int i = 1; i < 33; i++){
            if(n & 1){
                res = res | (1 << (32-i));
            }
            n >>= 1;
        }
        return res;

    }
};
