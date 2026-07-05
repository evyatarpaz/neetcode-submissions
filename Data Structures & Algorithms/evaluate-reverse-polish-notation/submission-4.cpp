class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> s;
        for(const std::string& token : tokens){
            if(token == "+" || token == "-" || token == "*" || token == "/"){
                int val1 = s.top();
                s.pop();
                int val2 = s.top();
                s.pop();
                int res;
                if(token == "+"){
                    res = val2 + val1;
                }else if(token == "-"){
                    res = val2 - val1;
                }else if(token == "*"){
                    res = val2 * val1;
                }else{
                    res = val2 / val1;
                }
                s.push(res);
            }else{
                s.push(std::stoi(token));
            }
        }
        return s.top();
    }
};

