#ifndef TETRIS_H
#define TETRIS_H

#include "shapes.h"
#include "Arduino.h"


class tetris {
    public:
    tetris();

    void clearScreen();

    void showScreen();

    bool checkForMovement(figure fig);

    void drawFigure(figure fig);

    void deleteFigure(figure fig);

    bool checkForWin();

    bool checkForLose();

    void printSad();

    void printHappy();

    figure *generateFigure();
};

#endif
