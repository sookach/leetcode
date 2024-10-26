class Solution {
public:
  vector<string> stringSequence(string target) {
    vector<string> v = {"a"};

    for (; v.back() != target;) {
      if (v.back().back() == target[size(v.back()) - 1]) {
        v.push_back(v.back() + "a");
      } else {
        v.push_back(v.back());
        ++v.back().back();
      }
    }

    return v;
  }
};
