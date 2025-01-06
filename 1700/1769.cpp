class Solution {
public:
  vector<int> minOperations(string boxes) {
    vector<int> v(size(boxes));

    for (int i = 0; i != size(boxes); ++i)
      if (boxes[i] == '1')
        for (int j = 0; j != size(v); ++j)
          v[j] += abs(i - j);

    return v;
  }
};
