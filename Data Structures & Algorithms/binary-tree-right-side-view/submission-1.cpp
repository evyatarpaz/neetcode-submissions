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
    vector<int> rightSideView(TreeNode* root) {
        std::vector<int> res;
        if(!root) return res;
        std::deque<TreeNode*> q = {root};

        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i < n; i++){
                TreeNode* node = q.front();
                q.pop_front();
                if(i == 0){
                    res.emplace_back(node->val);
                }
                if(node->right) q.push_back(node->right);
                if(node->left) q.push_back(node->left);

                // if(node->right){
                //     q.push_back(node->right);
                // }
                // if(node->left){
                //     q.push_back(node->left);
                // }
            }
        }
        return res;
    }
};
