#include <iostream>
#include <vector>
using namespace std;

bool dfs(int node, int parent, vector<vector<int>> edges,
         vector<bool> visited) {
  visited[node] = true;

  for (int x : edges[node]) {
    if (!visited[x]) {
      return dfs(x, node, edges, visited);
    }
    if (visited[x] && x != parent) {
      return true;
    }
  }

  return false;
}

int main() {
  int tam;
  cin >> tam;
  int v;
  cin >> v;

  vector<vector<int>> nodes(v, vector<int>());

  for (int i = 0; i < tam; i++) {
    int u, v;
    cin >> u >> v;
    nodes[u].push_back(v);
    nodes[v].push_back(u);
  }
  vector<bool> visited(v, false);
  cout << dfs(0, 0, nodes, visited);

  return 0;
}
