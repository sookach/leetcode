class Solution {
public:
  int countPrefixSuffixPairs(vector<string> &words) {
    int n = 0;

    for (int i = 0; i != size(words) - 1; ++i)
      for (int j = i + 1; j != size(words); ++j)
        n += static_cast<int>(
            size(words[i]) <= size(words[j]) &&
            words[j].substr(0, size(words[i])) == words[i] &&
            words[j].substr(size(words[j]) - size(words[i])) == words[i]);

    return n;
  }
};
