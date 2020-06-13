#ifndef SHAPES_H
#define SHAPES_H

#include "figure.h"

class squ : public figure
{
  private:
    int posx;
    int posy;
    /*-1-0-
      -3-2.*/
  public:
    squ(int posx_, int posy_) { //posx 1-7, posy 0-7
        posx = posx_;
        posy = posy_;
        
        position[0][0] = posx;
        position[0][1] = posy;

        position[1][0] = posx-1;
        position[1][1] = posy;

        position[2][0] = posx;
        position[2][1] = posy+1;

        position[3][0] = posx-1;
        position[3][1] = posy+1;
    }
};

class bar : public figure {
  private:
    int posx;
    int posy;
    /*0
      1
      3
      2*/
  public:
    bar(int posx_, int posy_) { //posx 0-7, posy 0-5
        posx = posx_;
        posy = posy_;
        
        position[0][0] = posx;
        position[0][1] = posy;

        position[1][0] = posx;
        position[1][1] = posy+1;

        position[2][0] = posx;
        position[2][1] = posy+3;

        position[3][0] = posx;
        position[3][1] = posy+2;
    }
};

class tblock : public figure {
  private:
    int posx;
    int posy;
    /*1-3-0
        2*/
  public:
    tblock(int posx_, int posy_) { //posx 1-7, posy 0-7
        posx = posx_;
        posy = posy_;
        
        position[3][0] = posx;
        position[3][1] = posy;

        position[1][0] = posx-1;
        position[1][1] = posy;

        position[2][0] = posx;
        position[2][1] = posy+1;

        position[0][0] = posx+1;
        position[0][1] = posy;
    }
};

class lblock : public figure {
  private:
    int posx;
    int posy;
    /*1-3-0
          2*/
  public:
    lblock(int posx_, int posy_) { //posx 1-7, posy 0-7
        posx = posx_;
        posy = posy_;
        
        position[3][0] = posx;
        position[3][1] = posy;

        position[1][0] = posx-1;
        position[1][1] = posy;

        position[2][0] = posx+1;
        position[2][1] = posy+1;

        position[0][0] = posx+1;
        position[0][1] = posy;
    }
};

#endif
