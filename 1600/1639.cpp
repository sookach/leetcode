class Solution {
public:
  int numWays(vector<string> &words, string target) {
    array<array<uint64_t, 26>, 1'000> a = {};
    array<array<uint64_t, 1'001>, 1'001> dp = {};

    for (auto &&x : words)
      for (int i = 0; i != size(x); ++i)
        a[i][x[i] - 'a'] = (a[i][x[i] - 'a'] + 1) % 1'000'000'007;

    ranges::fill(dp.front(), 1);

    for (int i = 1; i <= size(target); ++i)
      for (int j = 1; j <= size(words.front()); ++j)
        dp[i][j] =
            (dp[i][j - 1] + (dp[i - 1][j - 1] * a[j - 1][target[i - 1] - 'a']) %
                                1'000'000'007) %
            1'000'000'007;

    return dp[size(target)][size(words.front())];
  }
};
