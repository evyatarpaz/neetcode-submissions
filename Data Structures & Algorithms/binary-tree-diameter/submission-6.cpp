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
    int diameterOfBinaryTree(TreeNode* root) {
        int dim = 0;
        hight(root,dim);
        return dim;
    }
    
    int hight(TreeNode* root, int& d){
        if (root == nullptr){
            return 0;
        }
        int left = hight(root->left,d);
        int right = hight(root->right,d);


        d = std::max(d,right+left);
        return 1 + std::max(right,left);
    }
};
