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
    bool isValidBST(TreeNode* root) {
        return check(root, nullptr, nullptr);
    }

private:
    bool check(TreeNode* node, TreeNode* low, TreeNode* high) {
        if (!node) return true;
        if (low && node->val <= low->val) return false;
        if (high && node->val >= high->val) return false;
        return check(node->left, low, node) &&
               check(node->right, node, high);
    }
};