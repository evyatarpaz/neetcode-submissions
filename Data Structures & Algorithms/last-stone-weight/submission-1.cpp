class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // std::priority_queue<int> max_heap;
        std::make_heap(stones.begin(),stones.end());
        auto pop_and_return = [&stones](){
            int num = stones.front();
            std::pop_heap(stones.begin(),stones.end());
            stones.pop_back();
            return num;
        };
        auto push_val = [&stones](int val){
            stones.push_back(val);
            std::push_heap(stones.begin(),stones.end());
        };
        while(stones.size() > 1){
            int x = pop_and_return();
            int y = pop_and_return();

            if(x==y){
                continue;
            }
            x = x - y;
            push_val(x);
        }
        if(stones.size() == 1) return stones.front();
        return 0;

    }
};
