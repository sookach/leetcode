class Solution {
public:
  int threeSumMulti(vector<int> &arr, int target) {
    int n = 0;

    for (int i = 0; i != size(arr) - 2; ++i) {
      array<int, 101> a = {};
      for (int j = i + 1; j != size(arr); ++j) {
        if (clamp(target - arr[i] - arr[j], 0, 100) == target - arr[i] - arr[j])
          n = (n + a[target - arr[i] - arr[j]]) % 1'000'000'007;
        ++a[arr[j]];
      }
    }

    return n;
  }
};
