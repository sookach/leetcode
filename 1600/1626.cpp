class Solution {
public:
  int bestTeamScore(vector<int> &scores, vector<int> &ages) {
    vector<pair<int, int>> v;
    array<int, 1'000> dp = {};

    for (int i = 0; i != size(scores); ++i)
      v.emplace_back(ages[i], scores[i]);

    ranges::sort(v);

    for (int i = 0; i != size(v); ++i) {
      dp[i] = v[i].second;

      for (int j = 0; j != i; ++j)
        if (v[j].second <= v[i].second)
          dp[i] = max(dp[i], dp[j] + v[i].second);
    }

    return ranges::max(dp);
  }
};
