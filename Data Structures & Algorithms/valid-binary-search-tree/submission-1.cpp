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
    bool helper(TreeNode*root , long long mini , long long maxi){
        if(root == nullptr) return true;

        bool left = helper(root->left , mini , root->val);
        bool right = helper(root->right, root->val ,maxi);
        if(left && right && root->val > mini && root->val < maxi){
            return true;
        }
        return false;
    }
    bool isValidBST(TreeNode* root) {
        if(root == nullptr) return true;
        long long mini = LLONG_MIN;
        long long maxi = LLONG_MAX;
        return helper(root,mini,maxi);
    }
};
