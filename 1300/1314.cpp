class Solution {
public:
  vector<vector<int>> matrixBlockSum(vector<vector<int>> &mat, int k) {
    vector v(size(mat), vector<int>(size(mat.front())));

    for (int i = 0; i != size(v); ++i)
      for (int j = 0; j != size(v.front()); ++j)
        for (int r = max(i - k, 0); r != min<int>(i + k + 1, size(v)); ++r)
          for (int c = max(j - k, 0); c != min<int>(j + k + 1, size(v.front()));
               ++c)
            v[i][j] += mat[r][c];

    return v;
  }
};
