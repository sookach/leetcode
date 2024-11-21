class Solution {
public:
  vector<string> wordSubsets(vector<string> &words1, vector<string> &words2) {
    array<int, 26> a1 = {};
    vector<string> v;

    for (int i = 0; i != size(words2); ++i)
      for (array<int, 26> a2 = {}; auto &&x : words2[i])
        a1[x - 'a'] = max(a1[x - 'a'], ++a2[x - 'a']);

    for (auto &&x : words1) {
      array<int, 26> a2 = {};
      for (auto &&y : x)
        ++a2[y - 'a'];
      for (int i = 0; i != 26; ++i)
        if (a1[i] > a2[i])
          goto skip;
      v.push_back(std::move(x));
    skip:
    }

    return v;
  }
};
