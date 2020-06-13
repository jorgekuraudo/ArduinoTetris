#include "tetris.h"

#define HEIGHT 8
#define WIDTH 8

unsigned char HAPPY[9][10] = 
    {
      1,0,0,0,0,0,0,0,0,1,  
      1,0,1,1,0,0,1,1,0,1,  
      1,0,1,1,0,0,1,1,0,1,  
      1,0,0,0,0,0,0,0,0,1,  
      1,0,1,0,0,0,0,1,0,1,  
      1,0,0,1,1,1,1,0,0,1,  
      1,0,0,0,0,0,0,0,0,1,  
      1,0,0,0,0,0,0,0,0,1,
      1,1,1,1,1,1,1,1,1,1,
    };

unsigned char SAD[9][10] = 
    {
      1,0,0,0,0,0,0,0,0,1,  
      1,0,1,1,0,0,1,1,0,1,  
      1,0,1,1,0,0,1,1,0,1,  
      1,0,0,0,0,0,0,0,0,1,  
      1,0,0,0,0,0,0,0,0,1,  
      1,0,0,1,1,1,1,0,0,1,  
      1,0,1,0,0,0,0,1,0,1,  
      1,0,0,0,0,0,0,0,0,1,
      1,1,1,1,1,1,1,1,1,1,
    };

unsigned char SCREEN[9][10] = 
    {
      1,0,0,0,0,0,0,0,0,1,  
      1,0,0,0,0,0,0,0,0,1,  
      1,0,0,0,0,0,0,0,0,1,  
      1,0,0,0,0,0,0,0,0,1,  
      1,0,0,0,0,0,0,0,0,1,  
      1,0,0,0,0,0,0,0,0,1,  
      1,0,0,0,0,0,0,0,0,1,  
      1,0,0,0,0,0,0,0,0,1,
      1,1,1,1,1,1,1,1,1,1,
    };

int row[8] = {1, 3, 4, 5, 11, 10, 9, 8};
int col[8] = {A0, A1, A2, A3, A4, A5, 6, 7};

tetris::tetris() {
    for(int i = 0; i<8; ++i) {
    pinMode(row[i], OUTPUT);
    pinMode(col[i], OUTPUT);
}
}

void tetris::clearScreen() {
  for(int k=0; k<8; ++k) {
     digitalWrite(row[k], LOW);
     digitalWrite(col[k], HIGH);
  }
}

void tetris::showScreen() {
  for(int i = 0 ; i < 35 ; i++) {
    for(int c = 0; c<8; ++c) {  
      digitalWrite(col[c], LOW); 
      for(int r = 0; r<HEIGHT; ++r) {  
        digitalWrite(row[r], SCREEN[r][c+1]);  
      }  
      delay(1);
      this->clearScreen();
    }
  }
}

bool tetris::checkForMovement(figure fig) {
   bool canMove = true;
        for (int i = 0; i < 4; ++i) {
            int x = fig.position[i][0];
            int y = fig.position[i][1];
            if (SCREEN[y][x] == 1) {
                canMove = false;
            }
        }
        return canMove;
}

void tetris::drawFigure(figure fig) {
  for (int i = 0; i < 4; ++i) {
            int x = fig.position[i][0];
            int y = fig.position[i][1];
            SCREEN[y][x] = 1;
        }
        this->showScreen();
}

void tetris::deleteFigure(figure fig) {
   for (int i = 0; i < 4; ++i) {
            int x = fig.position[i][0];
            int y = fig.position[i][1];
            SCREEN[y][x] = 0;
        }
       this->showScreen();
}

bool tetris::checkForWin() {
  int actualRow = 0;
  for(int i = 0; i<8; ++i) {
    int count = 0;
    for(int j = 1; j<9; ++j) {
      if(SCREEN[i][j] == 1) {
        ++count;
      }
    }
    if(count == 8) {
      //shift the entire screen (TODO)
      for(int i = actualRow; i>=1; --i) {
        for(int j = 1; j<9; ++j) {
          SCREEN[i][j] = SCREEN[i-1][j]; 
        }
      }
      return true;
    }
    ++actualRow;
  }
  return false;
}

bool tetris::checkForLose() {
  for(int i = 1; i<9; ++i) {
    if (SCREEN[0][i] == 1) {
      return true;
    }
  }
  return false;
}

void tetris::printSad() {
  while(true) {
    for(int c = 0; c<8; ++c) {  
      digitalWrite(col[c], LOW); 
      for(int r = 0; r<HEIGHT; ++r) {  
        digitalWrite(row[r], SAD[r][c+1]);  
      }  
      delay(1);
      this->clearScreen();
    }
  }
}

void tetris::printHappy() {
  for(int i = 0 ; i < 100 ; i++) {
    for(int c = 0; c<8; ++c) {  
      digitalWrite(col[c], LOW); 
      for(int r = 0; r<HEIGHT; ++r) {  
        digitalWrite(row[r], HAPPY[r][c+1]);  
      }  
      delay(1);
      this->clearScreen();
    }
  }
}

figure *tetris::generateFigure() {
  //use 'random' arduino function
  int r = random(0,3);
        switch (r) {
            case 0: return new squ(random(2,8), 0);
            case 1: return new bar(random(1,8), 0);
            case 2: return new tblock(random(3,8), 0);
            case 3: return new lblock(random(3,8), 0);
        }
}

