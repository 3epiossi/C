using namespace std;
#define all(x) x.begin(), x.end()
class Solution {
public:
  string longestDiverseString(int a, int b, int c) {
    vector<pair<int, char>> v = {{a, 'a'}, {b, 'b'}, {c, 'c'}};
    sort(all(v), greater<pair<int, char>>());
    int mx = v[0].first;
    string ans;
    if (mx >= 2 * v[1].first + 2 * v[2].first + 2) {
      ans += v[0].second;
      ans += v[0].second;
      v[0].first -= 2;
      for (int i = 0; i < v[1].first; i++) {
        ans += v[1].second;
        if (!v[0].first)
          break;
        v[0].first--;
        ans += v[0].second;
        if (!v[0].first)
          break;
        v[0].first--;
        ans += v[0].second;
      }
      for (int i = 0; i < v[2].first; i++) {
        ans += v[2].second;
        if (!v[0].first)
          break;
        v[0].first--;
        ans += v[0].second;
        if (!v[0].first)
          break;
        v[0].first--;
        ans += v[0].second;
      }
    }
    // 2, 2, 2
    else {
      while (v[0].first || v[1].first || v[2].first) {
        sort(all(v), greater<pair<int, char>>());
        if (v[0].first > v[1].first) {
          if (v[0].first) {
            ans += v[0].second;
            v[0].first--;
          }
          if (v[0].first) {
            ans += v[0].second;
            v[0].first--;
          }
          if (v[1].first) {
            ans += v[1].second;
            v[1].first--;
          }
        } else {
          if (v[0].first) {
            ans += v[0].second;
            v[0].first--;
          }
          if (v[1].first) {
            ans += v[1].second;
            v[1].first--;
          }
        }
      }
    }
    return ans;
  }
};
