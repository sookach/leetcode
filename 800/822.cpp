class Solution {
public:
  int flipgame(vector<int> &fronts, vector<int> &backs) {
    bitset<2'0001> b1, b2;

    for (int i = 0; i != size(fronts); ++i)
      if (fronts[i] != backs[i])
        b1.set(fronts[i]), b1.set(backs[i]);
      else
        b2.set(fronts[i]);

    for (int i = 1; i != 2'001; ++i)
      if (b1.test(i) && !b2.test(i))
        return i;

    return 0;
  }
};
