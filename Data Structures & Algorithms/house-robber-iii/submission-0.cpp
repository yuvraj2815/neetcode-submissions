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
    int rob(TreeNode* root) {
        auto result=dfs(root);
        return max(result.first,result.second);
    }

    pair<int,int> dfs(TreeNode* node){
        if(!node) return {0,0};

        auto leftpair=dfs(node->left);
        auto rightpair=dfs(node->right);

        int wR=node->val+leftpair.second+rightpair.second;
        int woR=max(leftpair.first,leftpair.second)+max(rightpair.first,rightpair.second);

        return {wR,woR};
    }
};