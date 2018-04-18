#ifndef PLAYER_H
#define PLAYER_H

#include <string>

#include "ofMain.h"

class Player {
    public:

    Player();
    ofImage getCurrentImage();
    int getX();
    int getY();
    int getWidth();
    int getHeight();
    int getSize();
    void setX(int newX);
    void setY(int newY);
    void setUp();
    const int getEndOfGameYLevel();
    bool isFrogStillAlive();
    private:

    ofImage currentImage_;
    int x_;
    int y_;
    int width_;
    int height_;
    int size_;
    // kEndOfGameYLevel_ is simply when the player hits y = 0 (The frog crosses the road).
    const int kEndOfGameYLevel_ = 0;
    bool isAlive_;
};
#endif // PLAYER_H