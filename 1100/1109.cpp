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
  vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n) {
    vector<int> v;
    fenwick<20'001> f;

    for (auto &&x : bookings) {
      f.add(x.front(), x.back());
      f.add(x[1] + 1, -x.back());
    }

    for (int i = 1; i <= n; ++i)
      v.push_back(f.find(i));

    return v;
  }
};
