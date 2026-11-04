struct TrieNode{
    unordered_map<char,TrieNode*> children;
    string word = "";
};

class Solution {
private:
    void addWord(TrieNode* root, const string& word){
        TrieNode* curr = root;
        for(char c: word){
            if(!curr->children.count(c)){
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
        }
        curr->word = word;
    }

    void dfs(TrieNode* node,vector<vector<char>>& board, int r, int c, vector<string>& res){
        char temp = board[r][c];

        if(temp == '#' || !node->children.count(temp)) return;

        TrieNode* nextNode = node->children[temp];

        if(!nextNode->word.empty()){
            res.emplace_back(nextNode->word);
            nextNode->word = "";
        }
        board[r][c] = '#';

        int dr[] = {1,-1,0,0};
        int dc[] = {0,0,1,-1};

        for(int i = 0; i < 4; i++){
            int nr = r + dr[i], nc = c + dc[i];
            if(nr >= 0 && nr < board.size() && nc >=0 && nc < board[0].size()){
                dfs(nextNode,board,nr,nc,res);
            }
        }
        board[r][c] = temp;

        if(nextNode->children.empty()){
            delete nextNode;
            node->children.erase(temp);
        }
    }


public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for(const string& word : words){
            addWord(root,word);
        }

        vector<string> res;
        int ROWS = board.size();
        int COLS = board[0].size();


        for(int r = 0; r < ROWS; r++){
            for(int c = 0; c < COLS; c++){
                dfs(root,board,r,c,res);
            }
        }
        return res;
    }
};
