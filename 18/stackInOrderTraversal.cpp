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
    stack<TreeNode*> s;
    vector<int> res;
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == nullptr) return res;
        s.push(root);
        TreeNode* head = root->left;
        while(!s.empty() || head!=nullptr) {
            if(head != nullptr){
                s.push(head);
                head = head->left;
            }
            else if(head == nullptr){
                head = s.top();
                s.pop();
                res.push_back(head->val);
                head = head->right;
            }
        }
        return res;
    }
};