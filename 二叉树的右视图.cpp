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
    vector<int> ans;
    int max_height;

    void solve(TreeNode* node, int height) {
        if (node == nullptr) {
            return;
        }
        if (height > max_height) {
            ans.push_back(node -> val);
            max_height = height;
        }
        solve(node -> right, height + 1);
        solve(node -> left, height + 1);
    }

    vector<int> rightSideView(TreeNode* root) {
        max_height = 0;
        solve(root, 1);
        return ans;
    }
};
