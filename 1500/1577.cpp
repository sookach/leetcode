class Solution {
public:
  int numTriplets(vector<int> &nums1, vector<int> &nums2) {
    auto f = [](auto &&v1, auto &&v2) {
      int n = 0;

      for (uint64_t x : v1) {
        unordered_map<uint64_t, int> u;
        for (auto &&y : v2) {
          if (x * x % y == 0) {
            n += u[x * x / y];
            ++u[y];
          }
        }
      }

      return n;
    };

    return f(nums1, nums2) + f(nums2, nums1);
  }
};
