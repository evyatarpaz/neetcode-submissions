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
    vector<vector<int>> levelOrder(TreeNode* root) {
        std:vector<vector<int>> res;
        if(!root){
            return res;
        }
        std::deque<TreeNode*> q = {root};

        while(!q.empty()){
            int size = q.size();
            std::vector<int> ans;
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                ans.emplace_back(node->val);
                q.pop_front();
                if(node->left){
                    q.push_back(node->left);
                }
                if(node->right){
                    q.push_back(node->right);
                }
            }
            res.emplace_back(ans);
        }
        return res;
    }
};
