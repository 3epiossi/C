class Solution {
public:
  vector<string> buildArray(vector<int> &target, int n) {
    vector<string> stack = {};
    stack.push_back("Push");
    for (int i = 2; i <= target[0]; ++i) {
      stack.push_back("Pop");
      stack.push_back("Push");
    }
    int popcnt;
    for (auto t = target.begin(); t != target.end() - 1; ++t) {
      popcnt = *(t + 1) - *t - 1;
      for (int i = 0; i < popcnt; ++i) {
        stack.push_back("Push");
        stack.push_back("Pop");
      }
      stack.push_back("Push");
    }
    return stack;
  }
};
