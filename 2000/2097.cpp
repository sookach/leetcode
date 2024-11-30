class Solution {
public:
  vector<vector<int>> validArrangement(vector<vector<int>> &pairs) {
    unordered_map<int, vector<int>> u;
    unordered_map<int, int> d1, d2;
    vector<int> v1 = {pairs.front().front()}, v2;
    vector<vector<int>> v3;

    for (auto &&x : pairs) {
      u[x.front()].push_back(x.back());
      ++d1[x.back()];
      ++d2[x.front()];
    }

    for (auto &&[x, y] : d2) {
      if (y > d1[x]) {
        v1.back() = x;
        break;
      }
    }

    for (; !empty(v1);) {
      if (!empty(u[v1.back()])) {
        auto x = u[v1.back()].back();
        u[v1.back()].pop_back();
        v1.push_back(x);
      } else {
        v2.push_back(v1.back());
        v1.pop_back();
      }
    }

    ranges::reverse(v2);
    for (int i = 0; i != size(v2) - 1; ++i)
      v3.push_back({v2[i], v2[i + 1]});

    return v3;
  }
};
