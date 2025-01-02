class Solution {
public:
  vector<int> vowelStrings(vector<string> &words,
                           vector<vector<int>> &queries) {
    auto f = [](auto &&x) {
      switch (x) {
      case 'a':
      case 'e':
      case 'i':
      case 'o':
      case 'u':
        return 1;
      default:
        return 0;
      }
    };
    array<unsigned, 100'001> a = {};
    vector<int> v;

    for (int i = 0; i != size(words); ++i)
      a[i + 1] = a[i] + f(words[i].front()) * f(words[i].back());

    for (auto &&x : queries)
      v.push_back(a[x.back() + 1] - a[x.front()]);

    return v;
  }
};
