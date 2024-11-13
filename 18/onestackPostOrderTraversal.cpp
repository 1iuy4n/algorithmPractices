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
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==nullptr) return res;
        s.push(root);
        TreeNode* pre = root;
        while(!s.empty()){
            TreeNode* head = s.top();
            if(head->left != nullptr && head->left != pre && head->right != pre){
                s.push(head->left);
            }
            else if(head->right != nullptr && head->right != pre){
                s.push(head->right);
            }
            else{
                res.push_back(head->val);
                pre = s.top();
                s.pop();
            }
        }
        return res;
    }
};