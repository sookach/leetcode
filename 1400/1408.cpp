class Solution {
public:
  vector<string> stringMatching(vector<string> &words) {
    vector<string> v;

    for (auto &&x : words) {
      for (auto &&y : words) {
        if (x != y && !empty(ranges::search(y, x))) {
          v.push_back(x);
          break;
        }
      }
    }

    return v;
  }
};
