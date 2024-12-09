class Cashier {
  array<int, 201> a = {};
  int n, i = 0;
  double d;

public:
  Cashier(int n, int discount, vector<int> &products, vector<int> &prices)
      : n(n), d((100.0 - discount) / 100.0) {
    for (int i = 0; i != size(products); ++i) {
      a[products[i]] = prices[i];
    }
  }

  double getBill(vector<int> product, vector<int> amount) {
    double x = 0;

    for (int i = 0; i != size(product); ++i)
      x += a[product[i]] * amount[i];

    return x * (++i % n == 0 ? d : 1);
  }
};
