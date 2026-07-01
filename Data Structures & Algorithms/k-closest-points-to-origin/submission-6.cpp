class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto comp = [](const std::vector<int>& p1, const std::vector<int>& p2){
            return (p1[0] * p1[0] + p1[1] * p1[1]) < (p2[0] * p2[0] + p2[1] * p2[1]);
        };

        std::nth_element(points.begin(),points.begin() + k,points.end(),comp);

        return std::vector<std::vector<int>>(points.begin(), points.begin() + k);

    }
};
