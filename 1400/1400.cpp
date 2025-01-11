class Solution {
public:
  bool canConstruct(string s, int k) {
    if (size(s) < k)
      return false;
      
    bitset<26> b;

    for (auto &&x : s)
      b.flip(x - 'a');

    return b.count() <= k;
  }
};
