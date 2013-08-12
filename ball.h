/**
    PUNG by deosamox (ball.h)

    License details:

    The MIT License (MIT)
*/

#include <stdlib.h>
#include <time.h>

#define LIMX 79
#define LIMY 24

class Ball{
    private:
        char c;
        float speed;
        bool up, left, visible;
        int x, y;
    public:
        Ball(){
            c = '\2';
            restart();
        }

        void restart(){
            speed = 1;
            visible = true;
            srand(time(NULL));
            left = rand() % 2;
            srand(time(NULL));
            up = rand() % 2;
            srand(time(NULL));
            x = rand() % 20 + 30;
            srand(time(NULL));
            y = rand() % LIMY;
        }

        void getBeep(){
            Beep(800, 50);
        }

        bool isVisible(){
            return visible;
        }

        void setUp(bool up){
            this -> up = up;
        }

        bool getUp(){
            return up;
        }

        void setLeft(bool left){
            this -> left = left;
        }

        bool getLeft(){
            return left;
        }

        void setX(int x){
            this -> x = x;
        }

        int getX(){
            return x;
        }

        void setY(int y){
            this -> y = y;
        }

        int getY(){
            return y;
        }

        void setC(char c){
            this -> c = c;
        }

        char getC(){
            return c;
        }

        void move(){
            //Y
            if(y <= 0){
                up = false;
                getBeep();
            }
            if(y >= LIMY){
                up = true;
                getBeep();
            }
            if(up){
                y--;
            }
            else{
                y++;
            }
            //X
            if(x <= 0){
                visible = false;
            }
            if(x >= LIMX){
                visible = false;
            }
            if(left){
                x--;
            }
            else{
                x++;
            }
        }
};
