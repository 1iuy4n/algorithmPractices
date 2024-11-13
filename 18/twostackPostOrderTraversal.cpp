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
private:
    stack<TreeNode*> s1;
    stack<int> val1;
    vector<int> res;
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==nullptr) return res;
        s1.push(root);
        while(!s1.empty()){
            TreeNode *head = s1.top();
            val1.push(head->val);
            s1.pop();
            if(head->left!=nullptr) s1.push(head->left);
            if(head->right!=nullptr) s1.push(head->right);
        }
        while(!val1.empty()){
            res.push_back(val1.top());
            val1.pop();
        }
        return res;
    }
};