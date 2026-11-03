
struct TrieNode {
    std::vector<TrieNode*> chars;
    bool isWordEnd; 
    TrieNode() : chars(26, nullptr), isWordEnd(false) {}
};


class PrefixTree {
public:
    TrieNode* root;
    PrefixTree() {
        this->root = new TrieNode(); 
    }
    
    void insert(string word) {
        TrieNode* cur = this->root;
        for(int i = 0; i< word.size(); i++){
            int index = word[i] - 'a';
            if(!cur->chars[index]){
                cur->chars[index] = new TrieNode();
            }
            cur = cur->chars[index];
        }
        cur->isWordEnd = true;
    }
    
    bool search(string word) {
        TrieNode* cur = this->root;
        for(int i = 0; i < word.size(); i++){
            int index = word[i] - 'a';
            if(!cur->chars[index]) return false;
            cur = cur->chars[index];
        }
        return cur->isWordEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur = this->root;
        for(int i = 0; i < prefix.size(); i++){
            int index = prefix[i] - 'a';
            if(!cur->chars[index]) return false;
            cur = cur->chars[index];
        }
        return true;
    }
};
