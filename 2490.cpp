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
  bool isCircularSentence(string sentence) {
    auto v = split(sentence);

    for (auto y = v.back().back(); auto &&x : v)
      if (exchange(y, x.back()) != x.front())
        return false;

    return true;
  }
};
