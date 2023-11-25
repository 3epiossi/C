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
    int kthSmallest(TreeNode* root, int k) {
        idx = 1;
        dfs(root, k);
        return val;
    }
private:
    int idx;
    int val;
    bool dfs(TreeNode* cur, int k){
        bool flag = false;
        if(cur->left) flag = dfs(cur->left, k);
        if(flag) return true;
        if(idx == k){
            val = cur->val;
            return true;
        } 
        idx += 1;
        if(cur->right) flag = dfs(cur->right, k);
        return flag;
    }
};
