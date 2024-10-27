class Solution {
public:
  int countSquares(vector<vector<int>> &matrix) {
    auto f = [&](auto &&i, auto &&j) {
      return i != -1 && j != -1 ? matrix[i][j] : 0;
    };
    int n = 0;

    for (int j = 1; j != size(matrix.front()); ++j)
      matrix.front()[j] += matrix.front()[j - 1];

    for (int i = 1; i != size(matrix); ++i) {
      for (int j = 1; j != size(matrix.front()); ++j)
        matrix[i][j] += matrix[i][j - 1];
      for (int j = 0; j != size(matrix.front()); ++j)
        matrix[i][j] += matrix[i - 1][j];
    }

    for (int k = 1; k <= min(size(matrix), size(matrix.front())); ++k)
      for (int i = k - 1; i != size(matrix); ++i)
        for (int j = k - 1; j != size(matrix.front()); ++j)
          n += static_cast<int>(
              f(i, j) - f(i - k, j) - f(i, j - k) + f(i - k, j - k) == k * k);

    return n;
  }
};
