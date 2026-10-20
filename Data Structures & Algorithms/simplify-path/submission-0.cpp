class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        string cur;

        stringstream ss(path);

        while(std::getline(ss, cur, '/')){
            if(cur.empty()) continue;
            if(cur == ".."){
                if(!stack.empty()) stack.pop_back();
            }else if(!cur.empty() && cur != "."){
                stack.push_back(cur);
            }
        }
        string res = "/";
        for(int i = 0; i < stack.size(); i++){
            if(i>0) res += "/";
            res += stack[i];
        }

        return res;
    }
};