template <typename T> struct recursive final {
  const T F;

  constexpr recursive(T &&F) : F(std::forward<T>(F)) {}

  template <typename... Args>
  constexpr decltype(auto) operator()(Args &&...A) const noexcept {
    return F(std::cref(*this), std::forward<Args>(A)...);
  }
};

class Solution {
public:
  bool circularArrayLoop(vector<int> &nums) {
    for (int i = 0; i != size(nums); ++i)
      if (bitset<5'000> b;
          (i + nums[i] + size(nums)) % size(nums) != i &&
          recursive([&](auto &&self, int j) -> bool {
            if (i == j)
              return true;
            if (nums[i] * nums[j] < 0 || b.test(j))
              return false;
            b.set(j);
            return (self((j + nums[j] + size(nums)) % size(nums)));
          })((i + nums[i] + size(nums)) % size(nums)))
        return true;
    return false;
  }
};
