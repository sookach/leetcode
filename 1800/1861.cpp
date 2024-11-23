class Solution {
public:
  vector<vector<char>> rotateTheBox(vector<vector<char>> &box) {
    vector<vector<char>> v(size(box.front()));

    for (int i = size(box) - 1; i != -1; --i)
      for (int j = 0; j != size(box.front()); ++j)
        v[j].push_back(box[i][j]);

    for (int i = size(v) - 1; i != -1; --i) {
      for (int j = 0; j != size(v.front()); ++j) {
        if (v[i][j] != '#')
          continue;

        for (int k = i; k != size(v) - 1 && v[k + 1][j] == '.'; ++k)
          swap(v[k][j], v[k + 1][j]);
      }
    }

    return v;
  }
};
