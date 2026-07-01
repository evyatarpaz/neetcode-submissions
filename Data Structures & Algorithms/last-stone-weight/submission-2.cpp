class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        std::priority_queue<int> maxheap(stones.begin(),stones.end());

        while(maxheap.size() > 1){
            int x = maxheap.top();
            maxheap.pop();
            int y = maxheap.top();
            maxheap.pop();

            if(x > y){
                maxheap.push(x-y);
            }

        }   
        return maxheap.empty() ? 0 : maxheap.top();     
    }
};
