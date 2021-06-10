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
            printf("�Է°��� ������ ���Ե��� �ʽ��ϴ�. 0���� ó���մϴ�.\n");
            return 1;
        }
    }
    if (player[0] == player[1] | player[0] == player[2] | player[1] == player[2]) {
        printf("�Է°��� ���� ���� �����մϴ�. 0���� ó���մϴ�.\n");
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

    printf("<<<<���ھ߱��� �����մϴ�.>>>>\n");
    initiliaze();

    for (int i = 0; i < 3; i++) {
        printf("%d ", answer[i]);
    }
    printf("\n\n");
    printf("1ȸ���� 9ȸ���� �õ��� �� �ֽ��ϴ�\n\n");
    for (int ct = 0; ct < 9; ++ct) {
        printf("[%dȸ��]\n", ct + 1);
        printf("\n���� 3���� �Է��ϼ���(1 ~ 9������ ���ڸ� �Է� ���ڴ� 1ĭ�� ��� �մϴ�.) : ");

        get_input(player);

        compare_answer_player(answer, player);

        int victory = print_and_check_result();

        if (victory) {
            printf("�¸� �߽��ϴ�!\n");
            break;
        }

        if (ct == 8) {
            printf("9ȸ�� ������ �Ǿ����ϴ�. You lose!\n");
            break;
        }
    }
}