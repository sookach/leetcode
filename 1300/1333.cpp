class Solution {
public:
  vector<int> filterRestaurants(vector<vector<int>> &restaurants,
                                int veganFriendly, int maxPrice,
                                int maxDistance) {
    vector<int> v;

    for (int i = 0; i != size(restaurants); ++i)
      if ((veganFriendly == 0 || restaurants[i][2] == 1) &&
          restaurants[i][3] <= maxPrice && restaurants[i].back() <= maxDistance)
        v.push_back(i);

    ranges::sort(v, [&](auto &&x, auto &&y) {
      return restaurants[x][1] == restaurants[y][1]
                 ? restaurants[x].front() > restaurants[y].front()
                 : restaurants[x][1] > restaurants[y][1];
    });

    for (auto &&x : v)
      x = restaurants[x].front();

    return v;
  }
};
