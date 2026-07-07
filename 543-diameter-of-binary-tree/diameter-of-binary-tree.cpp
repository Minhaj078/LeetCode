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
    int ans = 0;

    int maxD(TreeNode* root){
        if(root == nullptr)return 0;

        int maxL = maxD(root->left);
        int maxR = maxD(root->right);

        ans = max(ans, maxL + maxR);
        return 1 + max(maxL, maxR);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        maxD(root);
        return ans;
    }
};