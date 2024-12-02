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
  int isPrefixOfWord(string sentence, string searchWord) {
    auto v = split(sentence);

    for (int i = 0; i != size(v); ++i)
      if (equal(cbegin(searchWord), cend(searchWord), cbegin(v[i])))
        return i + 1;

    return -1;
  }
};
