class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for(string str : strs){
            int len = str.size();
            res += to_string(len);
            res += '#';
            res += str;
        }
        return res;
    }

    vector<string> decode(string s) {
        int n = s.size();
        vector<string> res;
        if(n == 0) return res;
        int i  = 0;
        while(i<n){
            int j = i;
            while(s[j] != '#'){
                j++;
            }
            int len  = std::stoi(s.substr(i, j-i));
            res.emplace_back(s.substr(j+1,len));
            i = j+1+len;
        }
        return res;
    }
};
