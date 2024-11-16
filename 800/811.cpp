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
  vector<string> subdomainVisits(vector<string> &cpdomains) {
    unordered_map<string, int> u;
    vector<string> v;

    for (auto &&x : cpdomains) {
      auto s = split(x);
      auto n = stoi(s.front());

      u[s.back()] += n;
      for (size_t i = 0; (i = s.back().find('.', i)) != string::npos;)
        u[s.back().substr(++i)] += n;
    }

    for (auto &&[x, y] : u)
      v.push_back(to_string(y) + ' ' + x);

    return v;
  }
};
