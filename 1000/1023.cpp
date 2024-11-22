class Solution {
public:
  vector<bool> camelMatch(vector<string> &queries, string pattern) {
    vector<bool> v;

    for (auto &&x : queries) {
      int i = 0, j = 0;
      for (; i != size(x) && j != size(pattern); ++i) {
        if (x[i] == pattern[j]) {
          ++j;
          continue;
        }

        if (isupper(x[i]) && isupper(pattern[j]))
          break;
      }

      v.push_back(j == size(pattern) &&
                  none_of(cbegin(x) + i, cend(x), ::isupper));
    }

    return v;
  }
};
