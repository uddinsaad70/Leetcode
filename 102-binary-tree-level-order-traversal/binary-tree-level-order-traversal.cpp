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
    vector<TreeNode*> func(vector<vector<int>>& ans, vector<TreeNode*>parent){
        vector<int> temp;
        vector<TreeNode*> child;
        for(int i = 0; i < parent.size(); i++){
            if(parent[i]->left){
                temp.push_back(parent[i]->left->val);
                child.push_back(parent[i]->left);
            }
            if(parent[i]->right){
                temp.push_back(parent[i]->right->val);
                child.push_back(parent[i]->right);
            }
        }
        if(temp.size()){
            ans.push_back(temp);
            return child;
        }
        return child;
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;

        vector<TreeNode*>child;
        child.push_back(root);
        ans.push_back({root->val});
 
        while(child.size())
            child = func(ans, child);
        
        return ans;
    }
};