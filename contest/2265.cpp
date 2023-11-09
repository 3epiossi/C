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
private:
    map<TreeNode*, int> cache;
    int count = 0;
    int dfs(TreeNode* cur, int* sum){
        if(!cur){
            return 0;
        }
        map<TreeNode*, int>::iterator ptr = cache.find(cur);
        if( ptr != cache.end()){
            return ptr->second;
        }

        int subSum = cur->val;
        int count = 1 + dfs(cur->left, &subSum) + dfs(cur->right, &subSum);
        *sum += subSum;
        cache[cur] = subSum;
        if(cur->val == subSum/count)
            this->count += 1;
        return count;
    }
public:
    int averageOfSubtree(TreeNode* root) {
        int sum;
        dfs(root, &sum);
        return this->count;

    }
};
