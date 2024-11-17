class Solution {
public:
  string pushDominoes(string dominoes) {
    set<int> l1, l2, r1, r2;

    for (int i = 0; i != size(dominoes); ++i) {
      switch (dominoes[i]) {
      default:
        break;
      case 'L':
        l1.insert(-i);
        l2.insert(i);
        break;
      case 'R':
        r1.insert(-i);
        r2.insert(i);
      }
    }

    for (int i = 0; i != size(dominoes); ++i) {
      if (dominoes[i] != '.')
        continue;

      auto x1 = l1.lower_bound(-i), x2 = r1.lower_bound(-i),
           y1 = l2.lower_bound(i), y2 = r2.lower_bound(i);

      auto d1 = y1 != cend(l2) && (y2 == cend(r2) || *y1 < *y2)
                    ? *y1 - i
                    : numeric_limits<int>::max(),
           d2 = x2 != cend(r1) && (x1 == cend(l1) || *x2 < *x1)
                    ? i - -*x2
                    : numeric_limits<int>::max();

      dominoes[i] = d1 == d2 ? '.' : d1 < d2 ? 'L' : 'R';
    }

    return dominoes;
  }
};
