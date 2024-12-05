class Solution {
public:
  bool canChange(string start, string target) {
    auto i = start.find_first_of("LR"), j = target.find_first_of("LR");

    for (; i != string::npos && j != string::npos;) {
      if (start[i] != target[j] || start[i] == 'L' && i < j ||
          start[i] == 'R' && i > j)
        return false;
      start[i] = target[j] = '_';
      i = start.find_first_of("LR", i);
      j = target.find_first_of("LR", j);
    }

    return i == string::npos && j >= string::npos;
  }
};
