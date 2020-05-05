#ifndef BANDIT_H_INCLUDED
#define BANDIT_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generator() {
    time_t t;
    srand((unsigned) time(&t));
    int num = rand() % 10;
    return num;
}

char* spin(char spinned[], int wheel_id) {
    int randNum;
    randNum = generator();

    char* wheel_spinned;
    wheel_spinned = calloc(3, sizeof(wheel_spinned));

    int y = 0;
    for (int i=randNum; i < randNum+3; i++) {
        *(wheel_spinned + y) = spinned[i%10];
        y++;
    }
    return wheel_spinned;
}

void drawLines(int wheel_id) {
    for(int h = 1; h < wheel_id; h++){
        printf(" - ");
    }
}

int calcWin(int left, int center, int right) {
    int credits = 0;
    if(right == 'C')
        credits+=2;
    if((center == 'C' && right == 'C') || (center == 'B' && right == 'B'))
        credits+=8;
    if(left == 'C' && center == 'C' && right == 'C')
        credits+=12;
    if(left == 'B' && center == 'B' && right == 'B')
        credits+=16;
    if(left == 'O' && center == 'O' && right == 'O')
        credits+=10;
    if(left == 'A' && center == 'A' && right == 'A')
        credits+=18;
    if(left == 'P' && center == 'P' && right == 'P')
        credits+=24;
    if(left == 'G' && center == 'G' && right == 'G')
        credits+=24;
    if(left == 'R' && center == 'R' && right == 'R')
        credits+=50;
    return credits;
}

#endif // BANDIT_H_INCLUDED
