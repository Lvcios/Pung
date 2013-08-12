/**
    PUNG by deosamox (paddle.h)

    License details:

    The MIT License (MIT)
*/

#define RIGHT 0x4d
#define LEFT 0x4b
#define DOWN 0x50
#define UP 0x48

#define LIMX 79
#define LIMY 24

class Paddle{
    private:
        char c;
        int speed;
        int x, y;
        int dx, dy;
        bool player1;
    public:
        Paddle(){
            c = 219;
            speed = 2;
            y = LIMY / 2;
            isPlayer1(true);
            dx = 0;
            dy = 0;
        }

        void isPlayer1(bool player1){
            this -> player1 = player1;
            if(player1){
                this -> x = 10;
            }
            else {
                this -> x = 69;
            }
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
            if(y-1 <= 0){
                y = 1;
            }
            if(y+1 >= LIMY){
                y = LIMY-1;
            }

            y += dy * speed;
            dy = 0;
        }

        void input(){
            if(kbhit()){
                char tecla = getch();
                if(player1){
                    switch(tecla){
                        case 'w':
                        case 'W':
                            {
                                dy = -1;
                                break;
                            }
                        case 's':
                        case 'S':
                            {
                                dy = 1;
                                break;
                            }
                    }

                }
                else{
                    switch(tecla){
                        case UP:
                            {
                                dy = -1;
                                break;
                            }
                        case DOWN:
                            {
                                dy = 1;
                                break;
                            }
                    }
                }
            }
        }
};

