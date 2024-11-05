struct union_find final {
  unordered_map<string, string> P;
  unordered_map<string, unsigned> R;

  bool contains(string S) { return P.contains(S); }

  void insert(string S) {
    if (contains(S))
      return;
    P[S] = S;
    R[S] = 0;
  }

  string find(string S) { return P[S] == S ? S : P[S] = find(P[S]); }

  void unite(string S1, string S2) {
    auto X = find(S1), Y = find(S2);

    if (R[X] < R[Y])
      swap(X, Y);

    R[X] += static_cast<unsigned>(R[X] == R[Y]);
    P[Y] = X;
  }
};

class Solution {
public:
  vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
    union_find uf;
    unordered_map<string, vector<string>> u1;
    unordered_set<string> u2;
    vector<vector<string>> v;

    for (auto &&x : accounts) {
      uf.insert(x[1]);
      for (int i = 2; i != size(x); ++i) {
        uf.insert(x[i]);
        uf.unite(x[1], x[i]);
      }
    }

    for (auto &&[x, y] : uf.P)
      u1[uf.find(x)].push_back(x);

    for (auto &&x : accounts) {
      if (!u2.insert(uf.find(x.back())).second)
        continue;

      ranges::sort(u1[uf.find(x.back())]);
      v.emplace_back();
      v.back().push_back(x.front());
      ranges::move(u1[uf.find(x.back())], back_inserter(v.back()));
    }

    return v;
  }
};
