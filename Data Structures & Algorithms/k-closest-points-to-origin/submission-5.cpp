class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int left = 0, right = points.size() - 1;
        int pivot = right + 1;
        while(pivot != k){
            pivot = partition(points,left,right);
            if(pivot < k){
                left = pivot + 1;
            }else{
                right = pivot - 1;
            }
        }
        return std::vector<std::vector<int>> (points.begin(), points.begin() + k);
    }

    int partition(std::vector<std::vector<int>>& points, int left, int right){
        int pivot_idx = left + std::rand() % (right - left + 1);
        std::swap(points[pivot_idx], points[right]);


        pivot_idx = right;
        int pivot_dis = euc(points[pivot_idx]);
        int p = left;

        for(int i = left; i < right; i++){
            if(euc(points[i]) <= pivot_dis){
                std::swap(points[p], points[i]);
                p++;
            }
        }
        std::swap(points[p], points[right]);
        return p;
    }

    int euc(const std::vector<int>& point){
        return point[0] * point[0] + point[1] * point[1];
    }
};
