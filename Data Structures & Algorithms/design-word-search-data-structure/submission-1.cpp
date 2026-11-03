struct TrieNode {
    std::vector<TrieNode*> chars;
    bool isWordEnd; 
    TrieNode() : chars(26, nullptr), isWordEnd(false) {}
};


class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* cur = root;
        for(char c : word){
            int index = c - 'a';
            if(!cur->chars[index]){
                cur->chars[index] = new TrieNode();
            }
            cur = cur->chars[index];
        }
        cur->isWordEnd = true;
    }
    
    bool search(string word) {
        return searchWithDot(word,0,root);
    }

    bool searchWithDot(string& word,int index,TrieNode* node){
        if(!node) return false;
        if(index == word.size()){
            return node->isWordEnd;
        }

        char c = word[index];

        if(c == '.'){
            for(int i = 0; i<26;i++){
                if(node->chars[i] && searchWithDot(word,index+1,node->chars[i])){
                    return true;
                }
            }
            return false;
        }else{

            int charIndex = c - 'a';
            return searchWithDot(word,index+1,node->chars[charIndex]);

        }
    }
};
