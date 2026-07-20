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
    void solve(TreeNode* root,vector<int>&nums){
        if(root==NULL){
            return ;
        }
        solve(root->left,nums);
        nums.push_back(root->val);
        solve(root->right,nums);

    }
   
    bool isValidBST(TreeNode* root) {
        vector<int>nums;
        solve(root,nums);
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]<=nums[i-1]){
                return false;
            }
        }   
        return true;
    }
};
