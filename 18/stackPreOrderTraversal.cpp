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
//  #include <stack>
class Solution {
private:
    stack<TreeNode*> s;
    vector<int> res;
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == nullptr) return res;
        s.push(root);
        while(!s.empty()) {
            TreeNode* h = s.top();
            s.pop();
            res.push_back(h->val);
            if(h->right != nullptr) s.push(h->right);
            if(h->left != nullptr) s.push(h->left);
        }
        return res;
    }
};