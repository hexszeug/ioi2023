#include <iostream>
#include <map>
#include <string>

using namespace std;

struct Dish {
  int amount;
  float nom;
};

int main() {
  int n, m;
  cin >> n >> m;

  multimap<float, Dish> dishes;

  for (int i = 0; i < n; i++) {
    int amount;
    float nom;
    string name;
    cin >> name >> amount >> nom;
    Dish dish = {amount, nom};
    dishes.insert(pair<float, Dish>(nom, dish));
  }

  float totalNom = 0.0;

  for (auto pDish = dishes.rbegin(); pDish != dishes.rend(); pDish++) {
    if (m == 0)
      break;
    int amount = min(pDish->second.amount, m);
    totalNom += amount * pDish->second.nom;
    m -= amount;
  }

  cout << totalNom;

  return 0;
}