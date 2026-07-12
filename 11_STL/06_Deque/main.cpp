#include <deque>
#include <iostream>
#include <string>
using namespace std;

int main() {
  int n;
  deque<string> pedidos;
  deque<string> entrega;
  cin >> n;

  for (int i = 0; i < n; i++) {
    string cmd;
    cin >> cmd;

    if (cmd == "PEDIDO") {
      string sabor;
      cin >> sabor;
      pedidos.push_back(sabor);
    } else if (cmd == "FORNO_LIVRE") {
      string sabor = pedidos.front();
      pedidos.pop_front();
      entrega.push_back(sabor);
    } else if (cmd == "MOTOBOY") {
      string sabor = entrega.front();
      entrega.pop_front();
      cout << "ENTREGUE " << sabor << endl;
    } else if (cmd == "INSPECAO_FORNO") {
      int pos;
      cin >> pos;
      cout << pedidos[pos] << endl;
    } else if (cmd == "INSPECAO_ENTREGA") {
      int pos;
      cin >> pos;
      cout << entrega[pos] << endl;
    }
  }

  return 0;
}
