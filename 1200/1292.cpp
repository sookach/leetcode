class Solution {
public:
  int maxSideLength(vector<vector<int>> &mat, int threshold) {
    array<array<int, 301>, 301> a = {};
    int i = 0, j = min(size(mat), size(mat.front())) + 1;

    for (int i = 0; i != size(mat); ++i) {
      for (int j = 0; j != size(mat.front()); ++j)
        a[i + 1][j + 1] = a[i + 1][j] + mat[i][j];
      for (int j = 0; j != size(mat.front()); ++j)
        a[i + 1][j + 1] += a[i][j + 1];
    }

    for (; i != j - 1;)
      ([&](auto &&k) {
        for (int i = k; i <= size(mat); ++i) {
          for (int j = k; j <= size(mat.front()); ++j) {
            if (a[i][j] - a[i - k][j] - a[i][j - k] + a[i - k][j - k] <=
                threshold)
              return true;
          }
        }
        return false;
      }(i + (j - i) / 2)
           ? i
           : j) = i + (j - i) / 2;

    return i;
  }
};
