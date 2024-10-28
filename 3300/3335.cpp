class Solution {
public:
  int lengthAfterTransformations(string s, int t) {
    array<uint64_t, 26> a1 = {};

    for (auto &&x : s)
      ++a1[x - 'a'];

    for (; t-- != 0;) {
      array<uint64_t, 26> a2 = {};

      for (int i = 0; i != 25; ++i)
        a2[i + 1] = a1[i];

      a2.front() = (a2.front() + a1.back()) % 1'000'000'007;
      a2[1] = (a2[1] + a1.back()) % 1'000'000'007;
      a1 = std::move(a2);
    }

    return ranges::fold_left(
        a1, 0, [](auto &&x, auto &&y) { return (x + y) % 1'000'000'007; });
  }
};
