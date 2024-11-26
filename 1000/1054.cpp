class Solution {
public:
  vector<int> rearrangeBarcodes(vector<int> &barcodes) {
    array<int, 10'001> a = {};
    vector<pair<int, int>> v;

    for (auto &&x : barcodes)
      ++a[x];

    for (int i = 1; i != 10'001; ++i)
      if (a[i] != 0)
        v.emplace_back(i, a[i]);

    ranges::sort(v, greater(), &pair<int, int>::second);

    for (int i = 0; auto &&[x, y] : v) {
      for (; y != 0; --y) {
        if (i >= size(barcodes))
          i = 1;
        barcodes[i] = x;
        i += 2;
      }
    }

    return barcodes;
  }
};
