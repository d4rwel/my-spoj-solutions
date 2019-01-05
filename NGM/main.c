#include <stdio.h>
    
#define NIKIFOR 1
#define TROFIM 2

int main(int argc, char *argv[])
{
    int start;
    int winner;
    int winning_move;

    scanf("%d", &start);

    if (start % 10 == 0) {
        winner = TROFIM;
        winning_move = 9;
        printf("%d\n", winner);
    } else {
        winner = NIKIFOR;
        winning_move = start % 10;
        printf("%d\n%d\n", winner, winning_move);
    }
    
    return 0;
}
