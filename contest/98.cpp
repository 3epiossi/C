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
    bool isValidBST(TreeNode* root) {
        long long int lmin, rmax;
        TreeNode blank;
        blank.left = root;
        blank.right = NULL;
        blank.val = INT_MAX;
        return dfs(&blank, root, &lmin, &rmax);
    }
private:
    bool dfs(TreeNode* par, TreeNode* cur, long long int* Mn, long long int* Mx){
        long long int lmn = 3000000000, lmx = -3000000000, rmn = 3000000000, rmx = -3000000000;
        int lflag= true, rflag= true;
        if(cur->left){
            lflag = dfs(cur, cur->left, &lmn, &lmx);
        }
        if(cur->right){
            rflag = dfs(cur, cur->right, &rmn, &rmx);
        }
        *Mn = min({(long long int)cur->val, lmn, rmn});
        *Mx = max({(long long int)cur->val, lmx, rmx});
        if(!cur->left) lmx = -3000000000;
        if(!cur->right) rmn = 3000000000;
        return lflag && rflag && lmx < (long long int)cur->val && rmn > (long long int)cur->val;
    }
};
