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
private:
    vector<int> dfs(TreeNode* node){
        if(node==nullptr)return {1,0};

        vector<int> left=dfs(node->left);
        vector<int> right=dfs(node->right);

        bool balanced=(left[0]==1 && right[0]==1) && (abs(left[1]-right[1])<=1);
        int h=1+max(left[1],right[1]);

        return{balanced?1:0,h};
    }
public:
    bool isBalanced(TreeNode* root) {
        return dfs(root)[0]==1;
    }
};
