class Solution {
public:
  char findKthBit(int n, int k) {
    if (n == 1)
      return '0';

    int x = 1 << (n - 1);
    return k == x                                  ? '1'
           : k < x                                 ? findKthBit(n - 1, k)
           : findKthBit(n - 1, x - (k - x)) == '1' ? '0'
                                                   : '1';
  }
};
