std::vector<std::string> split(std::string_view S, char D = ' ') {
  std::vector<std::string> V;
  for (auto I = std::cbegin(S), E = std::cend(S); I != E;) {
    I = std::find_if(I, E, [D](char C) { return C != D; });
    if (I == E)
      break;
    auto J = std::find(I, E, D);
    V.emplace_back(I, J);
    if (J == E)
      break;
    I = J + 1;
  }
  return V;
}

class Solution {
public:
  string maskPII(string s) {
    if (ranges::contains(s, '@')) {
      ranges::transform(s, begin(s), ::tolower);
      auto v = split(s, '@');
      return string(1, v.front().front()) + string(5, '*') + v.front().back() +
             '@' + v.back();
    }

    string t;
    for (int i = size(s) - 1; i != -1 && size(t) != 4; --i)
      if (isdigit(s[i]))
        t.push_back(s[i]);
    ranges::reverse(t);
    switch (ranges::count_if(s, ::isdigit)) {
    default:
      return string("***-***-") + t;
    case 11:
      return string("+*-***-***-") + t;
    case 12:
      return string("+**-***-***-") + t;
    case 13:
      return string("+***-***-***-") + t;
    }
  }
};
