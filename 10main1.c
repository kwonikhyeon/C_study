#include <stdio.h>
#include <stdlib.h>   
#include <time.h> 

int strike = 0, ball = 0, level_selection;
int* player;
int* answer;

void initiliaze() {
    int num = 0;
    char YN = 'N';
    player = (int*)malloc(sizeof(int) * level_selection);
    answer = (int*)malloc(sizeof(int) * level_selection);
    
    srand((unsigned)time(NULL));

    for (int i = 0; i < level_selection;) {
        num = rand() % 9 + 1;
        for (int k = 0; k < level_selection; k++) {
            if (answer[k] == num)
                YN = 'Y';
        }
        if (YN == 'N')
            answer[i++] = num;
        else
            YN = 'N';
    }
    printf("����� ���� ��� : ");
    for (int i = 0; i < level_selection; i++) {
        printf("%d ", answer[i]);
    }
}

int check() {
    int count = 0;
    for (int i = 0; i < level_selection; i++) {
        if ((0 >= player[i]) | (player[i] > 9)) {
            printf("�Է°��� ������ ���Ե��� �ʽ��ϴ�.\n");
            return 1;
        }
    }
    
    for (int i = 0; i < level_selection; i++) {
        for (int k = 0; k < level_selection; k++) {
            if (player[k] == player[i]) {
                count += 1;
            }
        }
        if (count > 1) {
            printf("�Է°��� ���� ���� �����մϴ�.\n");
            return 1;
        }
        count = 0;
    }
    
    return 0;
}

void get_input() {
    for (int i = 0; i < level_selection; i++) {
        printf(">>>%d ��° �� : ", i + 1);
        scanf("%d", &player[i]);
    }
    
    if (check() == 1)
       return 0;
}

void compare_answer_player() {
    strike = 0;
    ball = 0;
   
    for (int i = 0; i < level_selection; i++) {
        if (answer[i] == player[i])
            strike += 1;
        else {
            for (int j = 0; j < level_selection; j++) {
                if (answer[i] == player[j])
                    ball += 1;
            }
        }
    }
}

int print_and_check_result() {
    printf("\nstrike : %d   ball : %d\n\n", strike, ball);
    if (strike == level_selection)
        return 1;
    else
        return 0;
}


void main() {
    int trial = 1;
    while (1) {
        printf("<<<<���ھ߱��� �����մϴ�.>>>>\n");
        printf("----<<%d��° �� �Դϴ�.>>----\n", trial);
        printf("���̵� ����->��� ���ڸ� �����ұ��?(0 = ����) : ");
        scanf("%d", &level_selection);
        if (level_selection == 0) {
            printf("<<<<���ھ߱��� �����մϴ�.>>>>\n");
            break;
        }
        initiliaze();
        printf("\n\n");
        printf("1ȸ���� 9ȸ���� �õ��� �� �ֽ��ϴ�\n\n");
        for (int ct = 0; ct < 9; ++ct) {
            printf("[%dȸ��]\n", ct + 1);
            printf("\n���� %d���� �Է��ϼ���(1 ~ 9������ ���ڸ� �Է� ���ڴ� 1ĭ�� ��� �մϴ�.)\n", level_selection);
            get_input();
            compare_answer_player();
            int victory = print_and_check_result();
            if (victory) {
                printf("�¸� �߽��ϴ�!\n\n");
                break;
            }
            if (ct == 8) {
                printf("9ȸ�� ������ �Ǿ����ϴ�. You lose!\n\n");
                break;
            }
        }
        free(answer);
        free(player);
        trial += 1;
    }
}