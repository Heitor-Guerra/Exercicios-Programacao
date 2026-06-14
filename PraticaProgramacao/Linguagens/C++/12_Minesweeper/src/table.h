#ifndef TABLE_H_
#define TABLE_H_

#define SIZE_TABLE 10

class Table {
private:
  static int table[2][SIZE_TABLE][SIZE_TABLE];
  int totalBombs;
  void revealAdjacent(int x, int y);

public:
  Table(int numBombs = SIZE_TABLE);
  void print();
  void printFull();
  int numBombsAround(int x, int y);
  bool markPosition();
  bool full();
  void revealZeros(int x, int y);
};

#endif
