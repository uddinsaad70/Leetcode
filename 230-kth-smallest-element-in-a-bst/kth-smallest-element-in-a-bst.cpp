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
    int res = -1;
    void kth(TreeNode* root, int k, int &i){
        if(!root) return;
        kth(root->left,k,i);
        if(++i==k) {
        res = root->val;
        return;
        }
        kth(root->right,k,i);
    }
    int kthSmallest(TreeNode* root, int k) {
        int i = 0;
        kth(root,k,i);
        return res;
    }
};