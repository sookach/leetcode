class Solution {
public:
  bool doesValidArrayExist(vector<int> &derived) {
    return ranges::fold_left(derived, 0, bit_xor()) == 0;
  }
};
