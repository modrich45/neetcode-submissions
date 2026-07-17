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
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        return max(1+maxDepth(root->left),1+maxDepth(root->right));
    }
    int solve(TreeNode* root,int &ans){
        if(root==NULL) return 0;
        int left=maxDepth(root->left);
        int right=maxDepth(root->right);
        ans=max(ans,left+right);
        ans=max(ans,solve(root->left,ans));
        ans=max(ans,solve(root->right,ans));
        return ans;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=INT_MIN;
        return solve(root,ans);
    }
};
