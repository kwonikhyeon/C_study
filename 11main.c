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
    printf("**참고용 정답 출력 : ");
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
    while (1) {
        for (int i = 0; i < level_selection; i++) {
            printf(">>>%d 번째 수 : ", i + 1);
            scanf("%d", &player[i]);
        }
        if (check() == 1)
            continue;
        else
            break;
    }
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

void save(int* v_data, int* l_data) {
    char v_d[10], l_d[10];
    FILE* data_save;
    data_save = fopen("C:\\Temp\\n_baseball_data.txt", "w");

    sprintf(v_d, "%d\n", *v_data);
    sprintf(l_d, "%d", *l_data);

    fputs(v_d, data_save);
    fputs(l_d, data_save);

    fclose(data_save);
    printf("저장이 완료되었습니다.\n\n");
}

int YorN() {
    int menu;
    while (1) {
        printf("1. 계속하기  2. 저장 후 계속  3. 저장 후 종료  4. 저장하지 않고 종료\n>>> ");
        scanf("%d", &menu);
        if (menu > 4 || menu < 0) {
            printf("1~4의 숫자를 입력해 주세요.\n");
            continue;
        }
        return menu;
    }
}

void call(int* v_data, int* l_data) {
    char v_d[10], l_d[10];
    FILE* data_call;
    if (data_call = fopen("C:\\Temp\\n_baseball_data.txt", "r")) {
        fgets(v_d, 10, data_call);
        *v_data = atoi(&v_d);
        fgets(l_d, 10, data_call);
        *l_data = atoi(&l_d);

        fclose(data_call);
        printf("데이터를 성공적으로 불러왔습니다.\n");
        printf("저장된 데이터>>> 승 : %d   패 : %d\n\n", *v_data, *l_data);
    }
    else
        printf("저장된 데이터가 존재하지 않습니다. 새로 시작합니다.\n\n");
}


void main() {
    int trial = 1;
    int v_count = 0, l_count = 0;
    char f;
    while (1) {
        printf("파일을 불러오시겠습니까?[y/n]\n>>> ");
        scanf(" %c", &f);
        if (f == 'y' || f == 'Y') {
            call(&v_count, &l_count);
            break;
        }
        else if (f == 'n' || f == 'N') {
            printf("불러오기 없이 게임을 시작합니다.\n\n");
            break;
        }
        else
            printf("잘못된 대답을 입력하셨습니다. 다시 입력해 주세요.\n");
    }
    while (1) {
        printf("<<<<숫자야구를 시작합니다.>>>>\n");
        printf("----<<%d번째 판 입니다.>>----\n", trial);
        printf("난이도 선택->몇개의 숫자를 생성할까요? : ");
        scanf("%d", &level_selection);
        if (level_selection <= 0) {
            printf("\n!!0보다 큰 수를 입력해주세요!!\n\n", v_count, l_count);
            continue;
        }
        initiliaze();
        printf("\n\n");
        printf("1회에서 9회까지 시도할 수 있습니다\n\n");
        for (int ct = 0; ct < 9; ++ct) {
            printf("[%d회차]\n", ct + 1);
            printf("\n숫자 %d개를 입력하세요(1 ~ 9까지의 숫자를 입력)\n", level_selection);
            get_input();
            compare_answer_player();
            int victory = print_and_check_result();
            if (victory) {
                printf("승리 했습니다!\n\n");
                v_count += 1;
                break;
            }
            if (ct == 8) {
                printf("9회가 마무리 되었습니다. You lose!\n\n");
                l_count += 1;
                break;
            }
        }  
        int n = YorN();
        if (n == 2 || n == 3) 
            save(&v_count, &l_count);
        if (n == 3 || n == 4) {
            printf("\n승 : %d번   패 : %d번\n", v_count, l_count);
            printf("<<<<숫자야구를 종료합니다.>>>>\n");
            break;
        }
        free(answer);
        free(player);
        trial += 1;
    }
}