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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root){
            return nullptr;
        }
        int r_v = root->val;
        int p_v = p->val;
        int q_v = q->val;

        if(r_v > q_v && r_v > p_v){
            return lowestCommonAncestor(root->left,p,q);
        }
        if(r_v < q_v && r_v < p_v){
            return lowestCommonAncestor(root->right,p,q);
        }
        return root;

    }
};
