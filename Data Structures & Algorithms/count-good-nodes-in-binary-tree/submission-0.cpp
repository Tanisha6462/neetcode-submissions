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
    int cnt;
    void helper(TreeNode* root , int mini){
        if(root == nullptr){
            return;
        }
        if(root->val >= mini){
            cnt += 1;
        }

        helper(root->left,max(root->val,mini));
        helper(root->right,max(root->val,mini));

    }
    int goodNodes(TreeNode* root) {
        if(root == nullptr) return 0;
        cnt = 0;
        helper(root,INT_MIN);
        return cnt;
    }
};
