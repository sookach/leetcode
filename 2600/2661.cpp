class Solution {
public:
  int firstCompleteIndex(vector<int> &arr, vector<vector<int>> &mat) {
    array<pair<int, int>, 100'001> a;
    array<int, 100'000> a1 = {}, a2 = {};

    for (int i = 0; i != size(mat); ++i)
      for (int j = 0; j != size(mat.front()); ++j)
        a[mat[i][j]] = {i, j};

    for (int i = 0; i != size(arr); ++i)
      if (auto [x, y] = a[arr[i]];
          ++a1[x] == size(mat.front()) || ++a2[y] == size(mat))
        return i;

    return size(arr);
  }
};
