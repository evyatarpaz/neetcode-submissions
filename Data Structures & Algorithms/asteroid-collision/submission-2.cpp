class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        std::vector<int> s;
        for(int& a : asteroids){
            while(!s.empty() && a < 0 && s.back() > 0){
                int diff = a + s.back();
                if(diff < 0){
                    s.pop_back();
                }else if(diff > 0){
                    a = 0;
                }else{
                    a = 0;
                    s.pop_back();
                }
            }
            if (a != 0){
                s.push_back(a);
            }
        }
        return s;
    }
};