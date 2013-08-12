/**
    PUNG by deosamox (game.h)

    License details:

    The MIT License (MIT)
*/
#include <iostream>
#include <conio.h>
#include <ctime>

#include "gotoxy.h"
#include "ball.h"
#include "paddle.h"

#define LIMX 79
#define LIMY 24


class Game {
    private:
        Ball ball;
        Paddle p1;
        Paddle p2;
        int score1, score2;
        bool inGame;

    public:
        Game(){
            inGame = true;
            score1 = 0;
            score2 = 0;
            p2.isPlayer1(false);
        }

        void remover(){
            //Remove Ball
            gotoxy(ball.getX(),ball.getY());
            std::cout << " ";

            //Render Player 1
            gotoxy(p1.getX(),(p1.getY()-1));
            std::cout << " ";
            gotoxy(p1.getX(),p1.getY());
            std::cout << " ";
            gotoxy(p1.getX(),(p1.getY()+1));
            std::cout << " ";

            //Render Player 2
            gotoxy(p2.getX(),(p2.getY()-1));
            std::cout << " ";
            gotoxy(p2.getX(),p2.getY());
            std::cout << " ";
            gotoxy(p2.getX(),(p2.getY()+1));
            std::cout << " ";
        }

        void render(){
            //Render Ball
            gotoxy(ball.getX(),ball.getY());
            std::cout << ball.getC();

            //Render Player 1
            gotoxy(p1.getX(),(p1.getY()-1));
            std::cout << p1.getC();
            gotoxy(p1.getX(),p1.getY());
            std::cout << p1.getC();
            gotoxy(p1.getX(),(p1.getY()+1));
            std::cout << p1.getC();

            //Render Player 2
            gotoxy(p2.getX(),(p2.getY()-1));
            std::cout << p2.getC();
            gotoxy(p2.getX(),p2.getY());
            std::cout << p2.getC();
            gotoxy(p2.getX(),(p2.getY()+1));
            std::cout << p2.getC();

            //Render Score
            gotoxy(20, LIMY / 8);
            std::cout << score1;
            gotoxy(60, LIMY / 8);
            std::cout << score2;
        }
        void checkCollisions(){
            //Player 1
            for(int i = -2; i < 3; i++){
                if((ball.getX() - 1) == p1.getX()){
                    if(ball.getY() == (p1.getY() + i)){
                        if(i < 0){
                            ball.setUp(true);
                            ball.setLeft(false);
                            ball.getBeep();
                            break;
                        }
                        else if(i == 0){
                            ball.setLeft(false);
                            ball.getBeep();
                            break;
                        }
                        else if(i > 0){
                            ball.setUp(false);
                            ball.setLeft(false);
                            ball.getBeep();
                            break;
                        }
                    }
                }
                if((ball.getX()) == p1.getX()){
                    if(ball.getY() == (p1.getY() + i)){
                        if(i < 0){
                            ball.setUp(true);
                            ball.getBeep();
                            break;
                        }
                        else if(i == 0){
                            ball.setLeft(false);
                            ball.getBeep();
                            break;
                        }
                        else if(i > 0){
                            ball.setUp(false);
                            ball.getBeep();
                            break;
                        }
                    }
                }
            }

            //Player 2
            for(int i = -2; i < 3; i++){
                if((ball.getX() + 1) == p2.getX()){
                    if(ball.getY() == (p2.getY() + i)){
                        if(i < 0){
                            ball.setUp(true);
                            ball.setLeft(true);
                            ball.getBeep();
                            break;
                        }
                        else if(i == 0){
                            ball.setLeft(true);
                            ball.getBeep();
                            break;
                        }
                        else if(i > 0){
                            ball.setUp(false);
                            ball.setLeft(true);
                            ball.getBeep();
                            break;
                        }
                    }
                }
                if((ball.getX()) == p1.getX()){
                    if(ball.getY() == (p1.getY() + i)){
                        if(i < 0){
                            ball.setUp(true);
                            ball.getBeep();
                            break;
                        }
                        else if(i == 0){
                            ball.setLeft(true);
                            ball.getBeep();
                            break;
                        }
                        else if(i > 0){
                            ball.setUp(false);
                            ball.getBeep();
                            break;
                        }
                    }
                }
            }
        }

        void gameState(){
            if(!ball.isVisible()){
                if(ball.getLeft()){
                    score2++;
                }
                else{
                    score1++;
                }
                ball.restart();
            }

        }

        void update(){
            ball.move();
            p1.input();
            p1.move();
            p2.input();
            p2.move();

            checkCollisions();
            gameState();

        }

        void run(){
            while (inGame){
                bool shouldRender = true;
                try{
                    Sleep(50);
                }
                catch(...){
                    shouldRender = false;
                }
                remover();
                update();

                //Render
                if (shouldRender) {
                    render();
                }

                //Easter Egg
                if(kbhit()){
                    char tecla = getch();
                    if(tecla == 0x3B){
                        inGame = false;
                        system("cls");
                        gotoxy((LIMX/2)-20,(LIMY/2)-5);
                        std::cout<<"Juego realizado por Samuel Morales Bender"<<std::endl;
                        gotoxy((LIMX/2)-7,(LIMY/2));
                        std::cout<<"Te amo Ennya <3"<<std::endl;
                        Sleep(5 * 1000);
                        break;
                    }
                }
            }
        }

};
