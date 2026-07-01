class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        std::priority_queue<std::pair<int,std::vector<int>>> max_heap;
        std::vector<std::vector<int>> ret;

        auto euc = [](const std::vector<int>& point){
            int ret = 0;
            for(int val : point){
                ret = ret + val*val;
            }
            return ret;
        };

        auto add = [&](const int dis,const std::vector<int> point){
            max_heap.emplace(dis,point);
            if(max_heap.size() > k){
                max_heap.pop();
            }
        };

        for(std::vector<int>& point : points){
            int ret = euc(point);
            add(ret,point);
        }

        while(!max_heap.empty()){
            ret.emplace_back(max_heap.top().second);
            max_heap.pop();
        }
        return ret;
    }
};
