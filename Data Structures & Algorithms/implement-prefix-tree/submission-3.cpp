

// Definition for Trie Node using std::unordered_map
struct TrieNode {
// Dynamically store child nodes corresponding to characters present
    std::unordered_map<char, TrieNode*> children;
    
    // Flag to mark the end of a valid word
    bool isWordEnd;

    // Constructor initializing isWordEnd to false
    TrieNode() : isWordEnd(false) {}
};

class PrefixTree {
private:
    TrieNode* root;

public:
    // Constructor initializes the root node
    PrefixTree() {
        root = new TrieNode();
    }

    // Inserts a word into the prefix tree
    void insert(const std::string& word) {
        TrieNode* cur = root;
        for (char c : word) {
        // If character doesn't exist in map, create a new TrieNode
            if (cur->children.find(c) == cur->children.end()) {
                cur->children[c] = new TrieNode();
            }
            // Move pointer to child node
            cur = cur->children[c];
        }
        // Mark the final node as the end of the word
        cur->isWordEnd = true;
    }

    // Returns true if the exact word exists in the prefix tree
    bool search(const std::string& word) {
        TrieNode* cur = root;
        for (char c : word) {
            // If character key is missing, word does not exist
            if (cur->children.find(c) == cur->children.end()) {
                return false;
            }
            cur = cur->children[c];
        }
        return cur->isWordEnd;
    }

// Returns true if there is any word in the prefix tree that starts with the given prefix
    bool startsWith(const std::string& prefix) {
        TrieNode* cur = root;
        for (char c : prefix) {
        // If character key is missing, prefix path does not exist
            if (cur->children.find(c) == cur->children.end()) {
                return false;
            }
            cur = cur->children[c];
        }
        return true;
    }
};