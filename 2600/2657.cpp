class Solution {
public:
  vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B) {
    bitset<51> b1, b2;
    vector<int> v;

    for (int i = 0; i != size(A); ++i) {
      b1.set(A[i]);
      b2.set(B[i]);
      v.push_back((b1 & b2).count());
    }

    return v;
  }
};
