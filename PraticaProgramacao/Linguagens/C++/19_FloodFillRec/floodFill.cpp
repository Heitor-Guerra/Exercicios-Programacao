#include <vector>
using namespace std;

#define SIZE 10

const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};

vector<vector<bool>> visited(10, vector<bool>(10, false));

void floodFill(vector<vector<int>> map, int y, int x, int value) {
  if (y < 0 || x < 0 || y >= map.size() || x >= map[0].size())
    return;
  else if (map[y][x] != value || visited[y][x] == true)
    return;

  visited[y][x] = true;

  for (int i = 0; i < 4; i++) {
    floodFill(map, y + dy[i], x + dx[i], value);
  }
}
