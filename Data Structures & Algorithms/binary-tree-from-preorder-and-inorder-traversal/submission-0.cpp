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
    int pre_idx = 0;
    std::unordered_map<int,int> indices;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); i++){
            indices[inorder[i]] = i;
        }

        return dfs(0,inorder.size() - 1,preorder);
    }

    TreeNode* dfs(int left, int right, const std::vector<int>& preorder){
        if(left > right){
            return nullptr;
        }

        int root_val = preorder[pre_idx++];
        TreeNode* root = new TreeNode(root_val);

        int mid = indices[root_val];

        root->left = dfs(left, mid - 1, preorder);
        root->right = dfs(mid + 1, right, preorder);
        return root;
    }
};
