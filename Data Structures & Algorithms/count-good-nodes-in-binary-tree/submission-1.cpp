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
        if(!root){
            return 0;
        }

        return countGood(root,root->val);

    }
private:
    int countGood(TreeNode* node, int max_val){
        if(!node){
            return 0;
        }
        int flag = 0;
        if(node->val >= max_val){
            flag = 1;
        }

        max_val = std::max(max_val,node->val);
        return flag + countGood(node->left,max_val) + countGood(node->right,max_val);
    }
};
