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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};                    // Fix 1

        queue<vector<TreeNode*>> q;
        vector<vector<int>> ans;

        vector<TreeNode*> temp = {root};         // Fix 2

        q.push(temp);

        while (!q.empty()) {                     // Fix 3
            vector<TreeNode*> vec = q.front();   // Fix 4
            q.pop();

            vector<int> level;                   // Fix 5
            vector<TreeNode*> curr;              // Fix 6

            for (auto &v : vec) {
                level.push_back(v->val);         // Fix 7

                if (v->left) curr.push_back(v->left);
                if (v->right) curr.push_back(v->right);
            }

            ans.push_back(level);                // Fix 8

            if (!curr.empty())                   // Fix 9
                q.push(curr);
        }

        return ans;
    }
};