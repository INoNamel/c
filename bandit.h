#ifndef BANDIT_H_INCLUDED
#define BANDIT_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generator();

char* spin(char spinned[], int wheel_id);

void drawLines(int wheel_id);

int calcWin(int left, int center, int right);

#endif // BANDIT_H_INCLUDED
