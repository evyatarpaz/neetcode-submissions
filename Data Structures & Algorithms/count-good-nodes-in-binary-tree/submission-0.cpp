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

class Solution {
public:
    int goodNodes(TreeNode* root) {
        std::queue<pair<TreeNode*,int>> q;
        if(!root){
            return 0;
        }
        q.emplace(root,root->val);
        int counter = 0;
        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i < n; i++){
                TreeNode* node = q.front().first;
                int max_val = q.front().second;
                q.pop();
                if(node->val >= max_val){
                    counter++;
                }
                if(node->left) q.emplace(node->left,max(max_val,node->left->val));
                if(node->right) q.emplace(node->right,max(max_val,node->right->val));
            }
        }
        return counter;
    }
};
