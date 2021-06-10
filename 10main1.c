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
    printf("참고용 정답 출력 : ");
    for (int i = 0; i < level_selection; i++) {
        printf("%d ", answer[i]);
    }
}

int check() {
    int count = 0;
    for (int i = 0; i < level_selection; i++) {
        if ((0 >= player[i]) | (player[i] > 9)) {
            printf("입력값이 범위에 포함되지 않습니다.\n");
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
            printf("입력값에 같은 수가 존재합니다.\n");
            return 1;
        }
        count = 0;
    }
    
    return 0;
}

void get_input() {
    for (int i = 0; i < level_selection; i++) {
        printf(">>>%d 번째 수 : ", i + 1);
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
        printf("<<<<숫자야구를 시작합니다.>>>>\n");
        printf("----<<%d번째 판 입니다.>>----\n", trial);
        printf("난이도 선택->몇개의 숫자를 생성할까요?(0 = 종료) : ");
        scanf("%d", &level_selection);
        if (level_selection == 0) {
            printf("<<<<숫자야구를 종료합니다.>>>>\n");
            break;
        }
        initiliaze();
        printf("\n\n");
        printf("1회에서 9회까지 시도할 수 있습니다\n\n");
        for (int ct = 0; ct < 9; ++ct) {
            printf("[%d회차]\n", ct + 1);
            printf("\n숫자 %d개를 입력하세요(1 ~ 9까지의 숫자를 입력 숫자는 1칸씩 띄고 합니다.)\n", level_selection);
            get_input();
            compare_answer_player();
            int victory = print_and_check_result();
            if (victory) {
                printf("승리 했습니다!\n\n");
                break;
            }
            if (ct == 8) {
                printf("9회가 마무리 되었습니다. You lose!\n\n");
                break;
            }
        }
        free(answer);
        free(player);
        trial += 1;
    }
}