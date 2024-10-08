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
  vector<int> exclusiveTime(int n, vector<string> &logs) {
    vector<int> v1(n);
    vector<pair<int, int>> v2;

    for (auto &&x : logs) {
      auto v3 = split(x, ':');
      if (v3[1] == "start") {
        if (!empty(v2))
          v1[v2.back().first] += stoi(v3.back()) - v2.back().second;
        v2.emplace_back(stoi(v3.front()), stoi(v3.back()));
      } else {
        v1[v2.back().first] += stoi(v3.back()) - v2.back().second + 1;
        v2.pop_back();
        if (!empty(v2))
          v2.back().second = stoi(v3.back()) + 1;
      }
    }

    return v1;
  }
};
