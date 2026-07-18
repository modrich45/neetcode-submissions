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
    void fillM(TreeNode* root, unordered_map<int, TreeNode*>& m) {
        if (root == NULL) return;

        if (root->left != NULL) {
            m[root->left->val] = root;
            fillM(root->left, m);
        }

        if (root->right != NULL) {
            m[root->right->val] = root;
            fillM(root->right, m);
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<int, TreeNode*> m;
        m[root->val] = NULL;
        fillM(root, m);

        vector<TreeNode*> p_r, q_r;

        TreeNode* temp = p;
        p_r.push_back(temp);
        while (m[temp->val] != NULL) {
            p_r.push_back(m[temp->val]);
            temp = m[temp->val];
        }

        temp = q;
        q_r.push_back(temp);
        while (m[temp->val] != NULL) {
            q_r.push_back(m[temp->val]);
            temp = m[temp->val];
        }

        int i = p_r.size() - 1, j = q_r.size() - 1;
        TreeNode* ans = NULL;

        while (i >= 0 && j >= 0 && p_r[i]->val == q_r[j]->val) {
            ans = p_r[i];
            i--;
            j--;
        }

        return ans;
    }
};