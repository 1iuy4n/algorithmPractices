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

#include <vector>
#include <utility>
#include <stack>

using namespace std;


class Solution {
private:
    stack<pair<TreeNode*, int>> s;
    vector<int> res;
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==nullptr) return res;
        s.push({root, 0});
        TreeNode* pre = root;
        while(!s.empty()){
            pair<TreeNode*, int> p = s.top();
            s.pop();
            if(p.first == nullptr) continue;
            else if(p.second == 0){
                s.push({p.first, 1});
                s.push({p.first->right, 0});
                s.push({p.first->left, 0});
            }
            else res.push_back(p.first->val);
        }
        return res;
    }
};