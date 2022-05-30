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
    vector<int> vec;

    void travel(TreeNode* node, string s) {
        if (node == nullptr) {
            return;
        }
        if (node -> left == nullptr && node -> right == nullptr) {
            int sum = 0;
            string tmp = s + to_string(node -> val);
            for (int i = 0; i < tmp.length(); i += 1) {
                sum = (sum << 1) + (tmp[i] - '0');
            }
            vec.push_back(sum);
        }
        travel(node -> left, s + to_string(node -> val));
        travel(node -> right, s + to_string(node -> val));
    }

    int sumRootToLeaf(TreeNode* root) {
        travel(root, "");
        int ans = 0;
        for (int item : vec) {
            ans += item;
        }
        return ans;
    }
};
