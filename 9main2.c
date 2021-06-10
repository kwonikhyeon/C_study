#include <stdio.h>
#include <stdlib.h>   
#include <time.h> 

int answer[3];
int strike = 0, ball = 0;

void initiliaze() {
    int num = 0;
    char YN = 'N';
    srand((unsigned)time(NULL));

    for (int i = 0; i < 3;) {
        num = rand() % 9 + 1;
        for (int k = 0; k < 3; k++) {
            if (answer[k] == num)
                YN = 'Y';
        }
        if (YN == 'N')
            answer[i++] = num;
        else
            YN = 'N';
    }
}

int check(int* player) {
    for (int i = 0; i < 3; i++) {
        if ((0 >= player[i]) | (player[i] > 9)) {
            printf("입력값이 범위에 포함되지 않습니다. 0으로 처리합니다.\n");
            return 1;
        }
    }
    if (player[0] == player[1] | player[0] == player[2] | player[1] == player[2]) {
        printf("입력값에 같은 수가 존재합니다. 0으로 처리합니다.\n");
        return 1;
    }
    return 0;
}


void get_input(int* player) {
    scanf("%d %d %d", &player[0], &player[1], &player[2]);
    if (check(player) == 1)
        player[0] = player[1] = player[2] = 0;
}

void compare_answer_player(int* answer, int* player) {
    strike = 0;
    ball = 0;
   
    for (int i = 0; i < 3; i++) {
        if (answer[i] == player[i])
            strike += 1;
        else
            for (int j = 0; j < 3; j++) {
                if (answer[i] == player[j])
                    ball += 1;
            }
        }
}

int print_and_check_result() {
    printf("\nstrike : %d   ball : %d\n\n", strike, ball);
    if (strike == 3)
        return 1;
    else
        return 0;
}

void main()
{
    int player[3];

    printf("<<<<숫자야구를 시작합니다.>>>>\n");
    initiliaze();

    for (int i = 0; i < 3; i++) {
        printf("%d ", answer[i]);
    }
    printf("\n\n");
    printf("1회에서 9회까지 시도할 수 있습니다\n\n");
    for (int ct = 0; ct < 9; ++ct) {
        printf("[%d회차]\n", ct + 1);
        printf("\n숫자 3개를 입력하세요(1 ~ 9까지의 숫자를 입력 숫자는 1칸씩 띄고 합니다.) : ");

        get_input(player);

        compare_answer_player(answer, player);

        int victory = print_and_check_result();

        if (victory) {
            printf("승리 했습니다!\n");
            break;
        }

        if (ct == 8) {
            printf("9회가 마무리 되었습니다. You lose!\n");
            break;
        }
    }
}