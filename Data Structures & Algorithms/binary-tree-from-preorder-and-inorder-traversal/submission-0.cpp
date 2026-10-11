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
    unordered_map<int,int> mpp;

    TreeNode* buildDFS(vector<int>& preorder,int preSt,int preEnd,vector<int>& inorder,int inSt,int inEnd){
        if(preSt>preEnd || inSt>inEnd) return nullptr;

        TreeNode* root= new TreeNode(preorder[preSt]);
        int inRoot=mpp[root->val];
        int numLeft=inRoot-inSt;

        root->left=buildDFS(preorder,preSt+1,preSt+numLeft,inorder,inSt,inRoot-1);
        root->right=buildDFS(preorder,preSt+numLeft+1,preEnd,inorder,inRoot+1,inEnd);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++) mpp[inorder[i]]=i;

        return buildDFS(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
    }
};
