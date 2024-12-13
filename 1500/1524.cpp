class Solution {
public:
  int numOfSubarrays(vector<int> &arr) {
    int n = 0, n1 = 1, n2 = 0;

    for (int y = 0; auto &&x : arr) {
      y += x;
      ++(y % 2 == 0 ? n1 : n2);
      n = (n + (y % 2 == 0 ? n2 : n1)) % 1'000'000'007;
    }

    return n;
  }
};
