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
    int kthSmallest(TreeNode* root, int k) {
        if(!root || k <= 0) return -1;
        vector<int> res;
        inorder(root,res,k);
        return res.empty() ? -1 : res.back();
    }
    void inorder(TreeNode* root,vector<int>& res, int k){
        if(!root || res.size() >= k) return;

        inorder(root->left, res, k);
        if(res.size() == k) return;
        res.emplace_back(root->val);
        inorder(root->right, res, k);
    }
};
