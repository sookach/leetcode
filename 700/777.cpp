class Solution {
public:
  bool canTransform(string start, string result) {
    auto i = start.find_first_of("LR"), j = result.find_first_of("LR");

    for (; i != string::npos && j != string::npos;) {
      if (start[i] != result[j] || start[i] == 'L' && i < j ||
          start[i] == 'R' && i > j)
        return false;
      start[i] = result[j] = 'X';
      i = start.find_first_of("LR", i);
      j = result.find_first_of("LR", j);
    }

    return i == string::npos && j >= string::npos;
  }
};
