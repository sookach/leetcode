class Solution {
public:
  vector<string> simplifiedFractions(int n) {
    vector<string> v;

    for (int i = 2; i <= n; ++i)
      v.push_back(to_string(1) + '/' + to_string(i));

    for (int i = 2; i <= n; ++i)
      for (int j = 2; j < i; ++j)
        if (gcd(i, j) == 1)
          v.push_back(to_string(j) + '/' + to_string(i));

    return v;
  }
};
