class Solution {
public:
  bool checkIfExist(vector<int> &arr) {
    bitset<7'000> b;

    for (auto &&x : arr) {
      if (b.test(2 * x + 2'000) || x % 2 == 0 && b.test(x / 2 + 2'000))
        return true;
      b.set(x + 2'000);
    }

    return false;
  }
};
