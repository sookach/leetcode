template <size_t N> struct fenwick final {
  std::array<int, N> a = {};

  constexpr void add(int i, int x) noexcept {
    for (; i < N; i += i & -i)
      a[i] += x;
  }

  constexpr int find(int i) noexcept {
    int x = 0;
    for (; i != 0; i -= i & -i)
      x += a[i];
    return x;
  }
};

class Solution {
public:
  string shiftingLetters(string s, vector<int> &shifts) {
    fenwick<100'001> f;

    for (int i = 0; i != size(shifts); ++i) {
      f.add(1, shifts[i] % 26);
      f.add(i + 2, -(shifts[i] % 26));
    }

    for (int i = 0; i != size(s); ++i) {
      s[i] = (s[i] - 'a' + f.find(i + 1)) % 26 + 'a';
    }

    return s;
  }
};
