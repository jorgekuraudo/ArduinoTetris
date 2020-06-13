#include <figure.h>
#include <shapes.h>
#include <tetris.h>

const int leftButton = 12;
const int rightButton = 13;
const int spinButton = 2;

void setup() {
  //Serial.begin(9600);
  pinMode(leftButton, INPUT);
  pinMode(rightButton, INPUT);
  pinMode(spinButton, INPUT);
}
   

tetris tetris;

void loop() {
    figure fig = *tetris.generateFigure();

    bool win = false;
    bool lost = false;
    bool canContinue = true;
        while (canContinue) {

        bool left = false;
        bool right = false;
        bool spin = false;
        if(digitalRead(leftButton) == HIGH) {
          left = true;
        } 
        if (digitalRead(rightButton) == HIGH) {
          right = true;
        }
        if (digitalRead(spinButton) == HIGH) {
          spin = true;
        }
          
        tetris.drawFigure(fig);
        tetris.deleteFigure(fig);

        if(spin == true) {
          fig.spin();
          if(tetris.checkForMovement(fig)==true) {
            tetris.drawFigure(fig);
            continue;
          } else {
            fig.spin();
            tetris.drawFigure(fig);
            continue;
          }
        }

        if(left == true) {
          fig.moveTo('L');
          if(tetris.checkForMovement(fig)==true) {
            tetris.drawFigure(fig);
            continue;
          } else {
            fig.moveTo('R');
            tetris.drawFigure(fig);
            continue;
          }
        }

        if(right == true) {
          fig.moveTo('R');
          if(tetris.checkForMovement(fig)==true) {
            tetris.drawFigure(fig);
            continue;
          } else {
            fig.moveTo('L');
            tetris.drawFigure(fig);
            continue;
          }
        }

        fig.moveTo('D');
        if(tetris.checkForMovement(fig)) {
            tetris.drawFigure(fig);
        } else {
            fig.moveTo('U');
            tetris.drawFigure(fig);
            canContinue = false;
        }
        }
        win = tetris.checkForWin();
        if (win) {
          tetris.printHappy();
        }
        lost = tetris.checkForLose();
        if (lost) {
          tetris.printSad();
        }
    
}
