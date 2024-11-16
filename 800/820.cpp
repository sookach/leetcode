class Solution {
public:
  int minimumLengthEncoding(vector<string> &words) {
    array<unordered_set<string>, 7> a;
    int n = 0;

    for (auto &&x : words)
      a[size(x) - 1].insert(x);

    for (int i = 0; i != size(a); ++i) {
      for (auto &&x : a[i]) {
        bool b = false;
        for (int j = i + 1; j != size(a) && !b; ++j)
          for (auto &&y : a[j])
            if ((b = x == y.substr(size(y) - size(x))))
              break;
        if (!b)
          n += size(x) + 1;
      }
    }

    return n;
  }
};
