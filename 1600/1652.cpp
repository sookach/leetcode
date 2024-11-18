class Solution {
public:
  vector<int> decrypt(vector<int> &code, int k) {
    vector<int> v;

    for (int i = 0; i != size(code); ++i) {
      if (k > 0) {
        v.emplace_back();
        for (int j = 1; j <= k; ++j)
          v.back() += code[(i + j) % size(code)];
      } else if (k < 0) {
        v.emplace_back();
        for (int j = -1; j >= k; --j)
          v.back() += code[(i + j + size(code)) % size(code)];
      } else {
        v.push_back(0);
      }
    }

    return v;
  }
};
