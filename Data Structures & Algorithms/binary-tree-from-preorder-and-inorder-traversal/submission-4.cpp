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
    int pre_idx = 0;
    int in_idx = 0;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder,inorder,INT_MIN);
    }

    TreeNode* build(const std::vector<int>& preorder, const std::vector<int> inorder, int stop){
        if(pre_idx == preorder.size()){
            return nullptr;
        }

        if(inorder[in_idx] == stop){
            in_idx++;
            return nullptr;
        }

        int root_val = preorder[pre_idx++];
        TreeNode* root = new TreeNode(root_val);

        root->left = build(preorder,inorder,root_val);
        root->right = build(preorder,inorder,stop);
        return root;
    }
};
