unsigned factorial(unsigned x) {
  static unordered_map<unsigned, unsigned> u;
  return u.contains(x) ? u.at(x) : u[x] = x < 2 ? 1 : x * factorial(x - 1);
}

class Solution {
public:
  int numberOfBoomerangs(vector<vector<int>> &points) {
    vector<unordered_map<double, unsigned>> v(size(points));

    for (int i = 0; i != size(points); ++i)
      for (int j = 0; j != size(points); ++j)
        if (i != j)
          ++v[i][pow(points[j].front() - points[i].front(), 2) +
                 pow(points[j].back() - points[i].back(), 2)];

    return ranges::fold_left(v, 0, [](auto &&x, auto &&y) {
      return x + ranges::fold_left(y, 0, [](auto &&x, auto &&y) {
               return x + (y.second < 2
                               ? 0
                               : factorial(y.second) / factorial(y.second - 2));
             });
    });
  }
};
