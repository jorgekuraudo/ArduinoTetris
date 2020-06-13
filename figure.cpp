#include "figure.h"

void figure::moveTo(char pos) {
  if (pos == 'D') {
      for (int i = 0; i<4; ++i) {
          position[i][1] = position[i][1] + 1;
      } 
  } else if (pos == 'R') {
      for (int i = 0; i<4; ++i) {
          position[i][0] = position[i][0] + 1;
      }
  } else if (pos == 'L') {
      for (int i = 0; i<4; ++i) {
          position[i][0] = position[i][0] -1;
      }
  } else if (pos == 'U') {
      for (int i = 0; i<4; ++i) {
          position[i][1] = position[i][1] - 1;
      }
  }
}

void figure::spin() {
    int blockNumber = 3;
    int pivot_i[2];
    int pivot_f[2];
    int distance[2];

    pivot_i[0] = position[blockNumber][0];
    pivot_i[1] = position[blockNumber][1];

    for (int i = 0; i<4; ++i) {
        int position_copy[i][0];
        position_copy[i][0] = position[i][0];
        position[i][0] = position[i][1];
        position[i][1] = position_copy[i][0];
    }

    pivot_f[0] = position[blockNumber][0];
    pivot_f[1] = position[blockNumber][1];

    distance[0] = pivot_f[0]-pivot_i[0];
    distance[1] = pivot_f[1]-pivot_i[1];
    
    for (int i=0; i<4; ++i) {
        position[i][0] -= distance[0];
        position[i][1] -= distance[1];
    }

}
