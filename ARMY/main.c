#include <stdio.h>

int read_num_testcase(void);
void do_testcase(void);


int main(int argc, char *argv[]) {
    int num_testcase;

    num_testcase = read_num_testcase();

    while(num_testcase) {
        do_testcase();
        num_testcase--;
    }

    return 0;
}

int read_num_testcase(void) {
    int num;

    scanf("%d", &num);

    return num;
}

void do_testcase(void) {
    char *winner = "Godzilla";
    int num_monster_mechgodzilla = 0;
    int num_monster_godzilla = 0;
    int strength_monster = 0;
    int highest_strength = 0;

    scanf("%d", &num_monster_godzilla);
    scanf("%d", &num_monster_mechgodzilla);

    for(int i = 0; i < num_monster_godzilla; i++) {
        scanf("%d", &strength_monster);
        if(strength_monster > highest_strength) {
            highest_strength = strength_monster;
        }
    }

    for(int i = 0; i < num_monster_mechgodzilla; i++) {
        scanf("%d", &strength_monster);
        if(strength_monster > highest_strength) {
            winner = "MechaGodzilla";
        }
    }

    printf("%s\n", winner);
}
