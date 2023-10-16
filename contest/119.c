#include <stdlib.h>
int *getRow(int rowIndex, int *returnSize) {
  int *row = (int *)calloc(rowIndex + 2, sizeof(int));
  int *prev = (int *)calloc(rowIndex + 2, sizeof(int));
  *returnSize = rowIndex + 1;
  prev[0] = 1;
  for (int i = 0; i <= rowIndex; ++i) {
    int *temp = row;
    row = prev;
    prev = temp;
    for (int r = 0; r <= i + 1; ++r) {
      if (r - 1 >= 0 && r <= i) {
        long long int num = (long long)row[r - 1] + (long long)row[r];
        prev[r] = (int)num;
      } else if (r > i) {
        prev[r] = 1;
      } else if (r - 1 < 0) {
        prev[r] = 1;
      }
    }
  }
  return row;
}
