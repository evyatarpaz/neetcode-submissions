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
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        return valid(root->left,root->val,INT_MIN) && valid(root->right,INT_MAX,root->val);
    }
    bool valid(TreeNode* root, int max, int min){
        if(!root) return true;

        if(root->val >= max || root->val <= min) return false;

        return valid(root->left,root->val,min) && valid(root->right,max,root->val);
    }
};
