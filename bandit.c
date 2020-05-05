#include <stdio.h>
#include <unistd.h>
#include "bandit.h"
#define BAR "BAR"

int main() {
    char a = 'A', b = 'B', c = 'C', g = 'G', l = 'L', o = 'O', p = 'P', r = 'R';
    char left_wheel[10] = {r,a,b,p,a,a,g,l,o,l};
    char center_wheel[10] = {r,c,c,b,b,p,a,g,o,l};
    char right_wheel[10] = {r,c,c,c,b,p,a,g,o,o};
    char continue_game[1];

    printf("\n Enter amount of credits:\n");

    int credits;
    char buf[3];
    char *endptr = NULL;
    char *input = NULL;
    input = fgets(buf, 4, stdin);
    credits = strtol(input, &endptr, 10);

    continue_game[0] = 'y';

    //START GAME
    if(credits > 0) {
        char* wheel_spinned;
        wheel_spinned = calloc(3, sizeof(wheel_spinned));

        char *left_wheel_spinned = (char *)malloc(3 * sizeof(char));
        char *center_wheel_spinned = (char *)malloc(3 * sizeof(char));
        char *right_wheel_spinned = (char *)malloc(3 * sizeof(char));
        int w, won;

        while(continue_game[0] == 'y')  {

            credits--;
            system("cls");
            printf("\n Spinning ...\n\n");

            //WHEEL #1 SPIN
            sleep(1);
            right_wheel_spinned = spin(right_wheel, 3);
            for(w = 0; w < 3; w++) {
                drawLines(3);
                if(right_wheel_spinned[w] == 'R') {
                    printf("%s\n", BAR);
                } else {
                    printf(" %c \n", right_wheel_spinned[w]);
                }
            }

            //WHEEL #2 SPIN
            sleep(1.5);
            system("cls");
            printf("\n Spinning ...\n\n");
            center_wheel_spinned = spin(center_wheel, 2);
            for(w = 0; w < 3; w++) {
                drawLines(2);
                if(center_wheel_spinned[w] == 'R') {
                    printf("%s", BAR);
                } else {
                    printf(" %c ", center_wheel_spinned[w]);
                }
                if(right_wheel_spinned[w] == 'R') {
                    printf("%s\n", BAR);
                } else {
                    printf(" %c \n", right_wheel_spinned[w]);
                }
            }

            //WHEEL #3 SPIN
            sleep(1.5);
            system("cls");
            printf("\n Result: \n\n");
            left_wheel_spinned = spin(left_wheel, 1);
            for(w = 0; w < 3; w++) {
                drawLines(1);
                if(left_wheel_spinned[w] == 'R') {
                    printf("%s", BAR);
                } else {
                    printf(" %c ", left_wheel_spinned[w]);
                }
                if(center_wheel_spinned[w] == 'R') {
                    printf("%s", BAR);
                } else {
                    printf(" %c ", center_wheel_spinned[w]);
                }
                if(right_wheel_spinned[w] == 'R') {
                    printf("%s", BAR);
                } else {
                    printf(" %c ", right_wheel_spinned[w]);
                }
                printf("\n");
                if(w == 1) {

                    won = calcWin(left_wheel_spinned[w], center_wheel_spinned[w], right_wheel_spinned[w]);
                    credits+=won;
                }
            }

            printf("\n\n Credits: %d | won: %d", credits, won);
            if(credits > 0) {
                printf("\n Continue? y/n\n");
                scanf(" %c", continue_game);
            } else {
                printf("\n You are broke!");
                break;
            }
        }

        free(wheel_spinned);
        free(left_wheel_spinned);
        free(center_wheel_spinned);
        free(right_wheel_spinned);

    }
    printf("\n GAME OVER");

    return 0;
}

