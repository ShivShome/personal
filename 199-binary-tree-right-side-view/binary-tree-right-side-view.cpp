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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans={};
        if(!root) return ans;
        queue< vector<TreeNode*> > q;

        q.push({root});
        while(!q.empty()){
            vector<TreeNode*> top=q.front();
            vector<TreeNode*>curr;
            q.pop();
            stack<int>st;
            for(auto&v:top){
                st.push(v->val);
                if(v->left)curr.push_back(v->left);
                if(v->right)curr.push_back(v->right);
            }
            if(!curr.empty()) q.push(curr);

            ans.push_back(st.top());
        }
        return ans;
    }
};