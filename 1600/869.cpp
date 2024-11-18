class Solution {
public:
  bool reorderedPowerOf2(int n) {
    static constexpr array a = {1,
                                2,
                                4,
                                8,
                                16,
                                32,
                                64,
                                128,
                                256,
                                512,
                                1'024,
                                2'048,
                                4'096,
                                8'192,
                                16'384,
                                32'768,
                                65'536,
                                131'072,
                                262'144,
                                524'288,
                                1'048'576,
                                2'097'152,
                                4'194'304,
                                8'388'608,
                                16'777'216,
                                33'554'432,
                                67'108'864,
                                134'217'728,
                                268'435'456,
                                536'870'912,
                                1'073'741'824};

    auto s = to_string(n);
    ranges::sort(s);

    do {
      if (s.front() == '0')
        continue;
      auto x = stoi(s);
      if (ranges::contains(a, x))
        return true;
    } while (ranges::next_permutation(s).found);

    return false;
  };
};
