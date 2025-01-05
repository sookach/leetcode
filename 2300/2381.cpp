class Solution {
public:
  string shiftingLetters(string s, vector<vector<int>> &shifts) {
    array<int, 50'001> a = {};

    for (auto &&x : shifts) {
      a[x.front()] += x.back() == 1 ? 1 : -1;
      a[x[1] + 1] += x.back() == 1 ? -1 : 1;
    }

    for (int i = 0, n = 0; i != size(s); ++i) {
      n = (n + a[i]) % 26;
      s[i] = (s[i] - 'a' + n + 26) % 26 + 'a';
    }

    return s;
  }
};
