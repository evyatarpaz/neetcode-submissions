class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int max_w = 1000;
        std::vector<int> buc(max_w+1,0);

        for(const int& stone : stones){
            buc[stone]++;
        }
        int curr = max_w;

        while(curr > 0){
            if(buc[curr] == 0){
                curr--;
                continue;
            }

            buc[curr] %= 2;
            if(buc[curr] == 1){
                int next_w = curr - 1;

                while(next_w > 0 && buc[next_w] == 0){
                    next_w--;
                }

                if(next_w == 0) return curr;

                buc[curr]--;
                buc[next_w]--;
                buc[curr - next_w]++;
                curr = std::max(next_w,(curr-next_w));

            }
        }
        return 0;
    }

};
