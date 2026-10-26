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
    bool isSame(TreeNode* p , TreeNode* q){
        if(p == nullptr && q == nullptr) return true;

        if(p == nullptr || q == nullptr) return false;

        if(p->val != q->val) return false;

        return isSame(p->left, q->left) && isSame(p->right,q->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            for(int i = 0 ; i < n ; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->val == subRoot->val){
                    if(isSame(node,subRoot)){
                        return true;
                    }
                }
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
        }

        return false;
    }
};
