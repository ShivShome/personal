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
int ans =0;
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        
        if(!root->left && !root->right) ans+=root->val;

        if(root->left){
            root->left->val+=(root->val)*10;
            sumNumbers(root->left);
        }

        if(root->right){
            root->right->val+=(root->val)*10;
            sumNumbers(root->right);
        }

        return ans;

    }
};