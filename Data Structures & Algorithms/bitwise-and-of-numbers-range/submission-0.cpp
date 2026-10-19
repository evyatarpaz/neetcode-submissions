class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int i = 0;
        while(right > left){
            right >>= 1;
            left >>=1;
            i++;
        }
        return right << i;
    }
};