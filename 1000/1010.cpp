class Solution {
public:
  int numPairsDivisibleBy60(vector<int> &time) {
    array<int, 501> a = {};
    int n = 0;

    for (auto &&x : time) {
      for (int i = 0; i != 501; ++i)
        n += static_cast<int>((x + i) % 60 == 0) * a[i];
      ++a[x];
    }

    return n;
  }
};
