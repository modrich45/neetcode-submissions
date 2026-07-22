class Solution {
public:
    unordered_map<int, int> m;
    int idx = 0;

    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int l, int r) {
        if (l > r) {
            return NULL;
        }

        int mid = m[preorder[idx]];
        TreeNode* temp = new TreeNode(preorder[idx]);
        idx++;

        temp->left = solve(preorder, inorder, l, mid - 1);
        temp->right = solve(preorder, inorder, mid + 1, r);

        return temp;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();

        for (int i = 0; i < n; i++) {
            m[inorder[i]] = i;
        }

        return solve(preorder, inorder, 0, n - 1);
    }
};