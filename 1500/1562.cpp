template <size_t N> struct union_find final {
  std::array<int, N> p, r = {}, a1 = {}, a2 = {};

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

    --a2[a1[x]];
    ++a2[a1[x] += a1[y]];
    --a2[a1[y]];
    a1[y] = 0;
  }
};

class Solution {
public:
  int findLatestStep(vector<int> &arr, int m) {
    union_find<100'001> u;
    int n = -1;

    for (int i = 0; i != size(arr); ++i) {
      ++u.a1[arr[i]];
      ++u.a2[1];

      if (arr[i] != 1 && u.a1[u.find(arr[i] - 1)] != 0)
        u.unite(arr[i], arr[i] - 1);

      if (arr[i] != size(arr) && u.a1[u.find(arr[i] + 1)] != 0)
        u.unite(arr[i], arr[i] + 1);

      if (u.a2[m] != 0)
        n = i + 1;
    }

    return n;
  }
};
