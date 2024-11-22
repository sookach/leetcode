class Solution {
public:
  int minDominoRotations(vector<int> &tops, vector<int> &bottoms) {
    auto n = numeric_limits<int>::max();

    for (int k = 1; k != 7; ++k) {
      int x = 0;
      for (int i = 0; i != size(tops); ++i) {
        if (tops[i] == k)
          continue;
        if (bottoms[i] != k)
          goto skip1;
        ++x;
      }
      n = min(n, x);

    skip1:
      x = 0;
      for (int i = 0; i != size(tops); ++i) {
        if (bottoms[i] == k)
          continue;
        if (tops[i] != k)
          goto skip2;
        ++x;
      }
      n = min(n, x);
    skip2:
    }

    return n == numeric_limits<int>::max() ? -1 : n;
  }
};
