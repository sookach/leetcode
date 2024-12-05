class Solution {
public:
  string removeDuplicates(string s, int k) {
    string t;

    for (auto &&x : s)
      if (t.push_back(x); size(t) >= k && t.substr(size(t) - k) == string(k, x))
        t.resize(size(t) - k);

    return t;
  }
};
