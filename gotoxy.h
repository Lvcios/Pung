#if defined (__WIN32__) || defined (WIN32)
    #define WIN32_FIXD
    #include <windows.h>
    #define gotoxy(x, y){ COORD a; a.X = x; a.Y = y; SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), a); }
#else
    #include <ncurses.h
    #define gotoxy(x,y) move(x,y)
#endif
