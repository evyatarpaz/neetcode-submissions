/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        std::ostringstream oss;
        std::queue<TreeNode*> q;
        q.emplace(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(!node){
                oss << "N,";
                continue;
            }
            oss << node->val << ",";
            q.emplace(node->left);
            q.emplace(node->right);
        }
        return oss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(const std::string& data) {
        if(data.empty() || data == "N,") return nullptr;

        char delimiter = ',';
        std::stringstream ss(data);
        std::string token;

        std::getline(ss,token,delimiter);
        // create the root of the tree
        TreeNode* root = new TreeNode(std::stoi(token));
        std::queue<TreeNode*> q;
        q.emplace(root);

        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();

            auto attach_child = [&](TreeNode*& child){
                if(std::getline(ss,token,delimiter) && token != "N"){
                    child = new TreeNode(std::stoi(token));
                    q.emplace(child);
                }
            };

            attach_child(curr->left);
            attach_child(curr->right);

            // if(std::getline(ss,token,delimiter)){
            //     if(token != "N"){
            //         curr->left = new TreeNode(std::stoi(token));
            //         q.emplace(curr->left);
            //     }
            // }
            // if(std::getline(ss,token,delimiter)){
            //     if(token != "N"){
            //         curr->right = new TreeNode(std::stoi(token));
            //         q.emplace(curr->right);
            //     }
            // }
        }
        return root;
    }
};
