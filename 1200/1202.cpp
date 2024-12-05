template <size_t N> struct union_find final {
  std::array<int, N> p, r = {};

  constexpr union_find() { std::iota(std::begin(p), std::end(p), 0); }

  constexpr int find(int i) noexcept {
    return p[i] == i ? i : p[i] = find(p[i]);
  }

  constexpr void unite(int i, int j) noexcept {
    auto x = find(i), y = find(j);

    if (r[x] < r[y])
      std::swap(x, y);

    r[x] += static_cast<int>(r[x] == r[y]);
    p[y] = x;
  }
};

class Solution {
public:
  string smallestStringWithSwaps(string s, vector<vector<int>> &pairs) {
    union_find<100'000> u;
    array<string, 100'000> a;

    for (auto &&x : pairs)
      u.unite(x.front(), x.back());

    for (int i = 0; i != size(s); ++i)
      a[u.find(i)].push_back(s[i]);

    for (auto &&x : a)
      ranges::sort(x, greater());

    for (int i = 0; i != size(s); ++i) {
      s[i] = a[u.find(i)].back();
      a[u.find(i)].pop_back();
    }

    return s;
  }
};
