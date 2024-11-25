class Solution {
public:
  int slidingPuzzle(vector<vector<int>> &board) {
    static const vector<vector<int>> v1 = {{1, 2, 3}, {4, 5, 0}};
    unordered_set<string> u;
    auto f = [](auto &&x) {
      return ranges::fold_left(x, string(), [](auto &&x, auto &&y) {
        return x + ranges::fold_left(y, string(), [](auto &&x, auto &&y) {
                 return x + to_string(y) + " ";
               });
      });
    };
    deque q = {board};
    u.insert(f(board));

    for (int x = 0; !empty(q); ++x) {
      for (auto n = size(q); n != 0; --n) {
        auto v2 = q.front();
        q.pop_front();

        if (v1 == v2)
          return x;

        int i = 0, j = 0;
        for (;; ++i)
          for (j = 0; j != 3; ++j)
            if (v2[i][j] == 0)
              goto done;

      done:
        if (i != 0) {
          swap(v2[i - 1][j], v2[i][j]);
          if (!u.contains(f(v2))) {
            u.insert(f(v2));
            q.push_back(v2);
          }
          swap(v2[i - 1][j], v2[i][j]);
        }

        if (i != 1) {
          swap(v2[i + 1][j], v2[i][j]);
          if (!u.contains(f(v2))) {
            u.insert(f(v2));
            q.push_back(v2);
          }
          swap(v2[i + 1][j], v2[i][j]);
        }

        if (j != 0) {
          swap(v2[i][j - 1], v2[i][j]);
          if (!u.contains(f(v2))) {
            u.insert(f(v2));
            q.push_back(v2);
          }
          swap(v2[i][j - 1], v2[i][j]);
        }

        if (j != 2) {
          swap(v2[i][j + 1], v2[i][j]);
          if (!u.contains(f(v2))) {
            u.insert(f(v2));
            q.push_back(v2);
          }
          swap(v2[i][j + 1], v2[i][j]);
        }
      }
    }

    return -1;
  }
};
