class Solution {
public:
  bool canReorderDoubled(vector<int> &arr) {
    auto f = [](auto &&m) {
      for (; !empty(m);) {
        auto x = *cbegin(m);
        m.erase(m.find(x));

        if (!m.contains(x * 2))
          return false;

        m.erase(m.find(x * 2));
      }

      return true;
    };
    multiset<int> m1, m2;

    for (auto &&x : arr)
      (x >= 0 ? m1 : m2).insert(abs(x));

    return f(m1) && f(m2);
  }
};
