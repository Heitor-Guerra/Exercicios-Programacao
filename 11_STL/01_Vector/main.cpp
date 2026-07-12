#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef struct {
  string name;
  float price;
  float discount;
  unsigned int qtd;
  unsigned int sales;
} Produto;

Produto *product_construct(string name, float price, float discount,
                           unsigned int qtd, unsigned int sales) {
  Produto *p = new Produto;
  p->name = name;
  p->price = price;
  p->discount = discount;
  p->qtd = qtd;
  p->sales = sales;

  return p;
}

void product_destroy(Produto *p) { delete p; }

int main() {
  vector<Produto *> v;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string name;
    float price;
    unsigned int qtd;
    unsigned int sales;

    cin.ignore();
    getline(cin, name);
    cin >> price;
    cin >> qtd;
    cin >> sales;

    v.push_back(product_construct(name, price, 0, qtd, sales));
  }

  char c;
  cin >> c;
  switch (c) {
  case 'N':
    sort(v.begin(), v.end(),
         [](const Produto *a, const Produto *b) { return a->name < b->name; });
    break;
  case 'P':
    sort(v.begin(), v.end(), [](const Produto *a, const Produto *b) {
      return a->price < b->price;
    });
    break;
  case 'S':
    sort(v.begin(), v.end(), [](const Produto *a, const Produto *b) {
      return a->sales < b->sales;
    });

    break;
  }

  for (Produto *a : v) {
    printf("Product(%s, %.2f, %.2f, %.2f, %d, %d)\n", a->name.c_str(), a->price,
           a->discount, a->price, a->qtd - a->sales, a->sales);
    product_destroy(a);
  }

  return 0;
}
