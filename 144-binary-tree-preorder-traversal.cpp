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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
};

#include <vector>

using namespace std;

class Solution {
private:
    vector<int> ans;
public:
    vector<int> preorderTraversal(TreeNode* root) {
        traversal(root);
        return ans;
    }
private:
    void traversal(TreeNode *root) {
        if (root != nullptr) {
            ans.push_back(root->val);
            traversal(root->left);
            traversal(root->right);
        }
    }
};
