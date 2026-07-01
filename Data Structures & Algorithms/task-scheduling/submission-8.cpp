class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        std::vector<int> counts(26,0);

        for(const char task : tasks){
            int idx = task - 'A';
            counts[idx]++;
        }

        std::priority_queue<int> max_heap;
        for(const int count : counts){
            if(count){
                max_heap.emplace(count);
            }
        }

        std::queue<pair<int,int>> cooldown;
        int time = 0;

        while(!max_heap.empty() || !cooldown.empty()){
            time++;

            if(!max_heap.empty()){
                int curr = max_heap.top();
                max_heap.pop();
                curr--;
                if(curr){
                    cooldown.emplace(curr,time+n);
                }
            }

            if(!cooldown.empty() && cooldown.front().second == time){
                max_heap.emplace(cooldown.front().first);
                cooldown.pop();
            }

        }
        return time;
    }
};
