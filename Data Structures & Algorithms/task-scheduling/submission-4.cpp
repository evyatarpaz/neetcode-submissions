class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        std::vector<int> counts(26,0);
        int max_val = 0;
        for(const char task : tasks){
            int idx = (task - 'A');
            counts[idx]++;
            max_val = std::max(max_val,counts[idx]);
        }

        int max_count = 0;
        for(const int count : counts){
            if(count == max_val){
                max_count++;
            }
        }
        int ans = (max_val - 1) * (n+1) + max_count;
        return max((int)tasks.size(),ans);
    }
};
