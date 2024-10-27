class Solution {
public:
  int maxScore(int n, int k, vector<vector<int>> &stayScore,
               vector<vector<int>> &travelScore) {
    array<array<int, 200>, 201> dp = {};

    for (int i = 0; i != k; ++i) {
      for (int j = 0; j != n; ++j) {
        dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + stayScore[i][j]);
        for (int c = 0; c != n; ++c) {
          dp[i + 1][c] = max(dp[i + 1][c], dp[i][j] + travelScore[j][c]);
        }
      }
    }

    return ranges::max(dp[k]);
  }
};
