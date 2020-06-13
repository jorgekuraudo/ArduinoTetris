#ifndef FIGURE_H
#define FIGURE_H

class figure {
  public:
    //blocks position
    int position[4][2]; //{block1, {x1, y1}}, {block2, {x2, y2}}, ... }
    /*explanation: 0 stops movement to the right.
                    1 stops movements to the left.
                    2 stops downwards movement.
                    3 is nothing (for now).*/

    void moveTo(char pos);
        //move all blocks one square down/right/left

    void spin();
};
#endif
