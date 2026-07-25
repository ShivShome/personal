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
   vector<double> averageOfLevels(TreeNode* root) {
    if (!root) return {};

    queue<vector<TreeNode*>> q;
    q.push({root});

    vector<double> ans;

    while (!q.empty()) {
        vector<TreeNode*> temp = q.front();
        q.pop();

        vector<TreeNode*> curr;
        double sum = 0;

        for (auto &v : temp) {
            sum += v->val;

            if (v->left) curr.push_back(v->left);
            if (v->right) curr.push_back(v->right);
        }

        ans.push_back(sum / temp.size());

        if (!curr.empty())
            q.push(curr);
    }

    return ans;
}
};