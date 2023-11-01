class Solution {
public:
  vector<int> findMode(TreeNode *root) {
    traverse(root);
    return res;
  }

private:
  vector<int> res;
  int curCount = 0;
  int Max = 0;
  int curVal = 0;
  void traverse(TreeNode *root) {
    if (!root) {
      return;
    }

    traverse(root->left);
    if (root->val != curVal) {
      curCount = 1;
    } else {
      ++curCount;
    }
    if (curCount == Max) {
      res.push_back(root->val);
    } else if (curCount > Max) {
      Max = curCount;
      res = {root->val};
    }
    curVal = root->val;
    traverse(root->right);
    return;
  }
};
