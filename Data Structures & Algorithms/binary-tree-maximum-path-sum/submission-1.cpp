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
    int maxPathSum(TreeNode* root) {
        int max_path = INT_MIN;
        dfs(root,max_path);
        return max_path;
    }

    int dfs(TreeNode* node, int& max_path){
        if(!node) return 0;

        int left = dfs(node->left,max_path);
        int right = dfs(node->right,max_path);

        max_path = max(max_path,node->val + max(0,left) + max(0,right));
        return node->val + max(0,max(left,right));

    }
};
