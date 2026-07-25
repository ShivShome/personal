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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        if(!root) return {};

        bool flag = true;

        queue< vector<TreeNode*> > q;
        vector<vector<int>> ans;
        q.push({root});

        while(!q.empty()){
           vector<TreeNode*> top = q.front();
           q.pop();

           vector<int> level;
           vector<TreeNode*> curr;
           
           for(auto &v:top){
            level.push_back(v->val);

            if (v->left) curr.push_back(v->left);
            if (v->right) curr.push_back(v->right);
           }

           if(!curr.empty())
        q.push(curr);

            if(flag){
                ans.push_back(level);
                flag=false;
            } 

           else{
    flag = true;
    reverse(level.begin(), level.end());   // Fix
    ans.push_back(level);
}
    
        }

        return ans;
    }

};