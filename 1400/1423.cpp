class Solution {
public:
  int maxScore(vector<int> &cardPoints, int k) {
    int n1 = accumulate(cbegin(cardPoints), cbegin(cardPoints) + k, 0), n2 = n1;

    for (int i = k - 1; i != -1; --i) {
      n2 += cardPoints[size(cardPoints) - k + i] - cardPoints[i];
      n1 = max(n1, n2);
    }

    return n1;
  }
};
