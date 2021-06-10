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
    printf("**����� ���� ��� : ");
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
    while (1) {
        for (int i = 0; i < level_selection; i++) {
            printf(">>>%d ��° �� : ", i + 1);
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
    printf("������ �Ϸ�Ǿ����ϴ�.\n\n");
}

int YorN() {
    int menu;
    while (1) {
        printf("1. ����ϱ�  2. ���� �� ���  3. ���� �� ����  4. �������� �ʰ� ����\n>>> ");
        scanf("%d", &menu);
        if (menu > 4 || menu < 0) {
            printf("1~4�� ���ڸ� �Է��� �ּ���.\n");
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
        printf("�����͸� ���������� �ҷ��Խ��ϴ�.\n");
        printf("����� ������>>> �� : %d   �� : %d\n\n", *v_data, *l_data);
    }
    else
        printf("����� �����Ͱ� �������� �ʽ��ϴ�. ���� �����մϴ�.\n\n");
}


void main() {
    int trial = 1;
    int v_count = 0, l_count = 0;
    char f;
    while (1) {
        printf("������ �ҷ����ðڽ��ϱ�?[y/n]\n>>> ");
        scanf(" %c", &f);
        if (f == 'y' || f == 'Y') {
            call(&v_count, &l_count);
            break;
        }
        else if (f == 'n' || f == 'N') {
            printf("�ҷ����� ���� ������ �����մϴ�.\n\n");
            break;
        }
        else
            printf("�߸��� ����� �Է��ϼ̽��ϴ�. �ٽ� �Է��� �ּ���.\n");
    }
    while (1) {
        printf("<<<<���ھ߱��� �����մϴ�.>>>>\n");
        printf("----<<%d��° �� �Դϴ�.>>----\n", trial);
        printf("���̵� ����->��� ���ڸ� �����ұ��? : ");
        scanf("%d", &level_selection);
        if (level_selection <= 0) {
            printf("\n!!0���� ū ���� �Է����ּ���!!\n\n", v_count, l_count);
            continue;
        }
        initiliaze();
        printf("\n\n");
        printf("1ȸ���� 9ȸ���� �õ��� �� �ֽ��ϴ�\n\n");
        for (int ct = 0; ct < 9; ++ct) {
            printf("[%dȸ��]\n", ct + 1);
            printf("\n���� %d���� �Է��ϼ���(1 ~ 9������ ���ڸ� �Է�)\n", level_selection);
            get_input();
            compare_answer_player();
            int victory = print_and_check_result();
            if (victory) {
                printf("�¸� �߽��ϴ�!\n\n");
                v_count += 1;
                break;
            }
            if (ct == 8) {
                printf("9ȸ�� ������ �Ǿ����ϴ�. You lose!\n\n");
                l_count += 1;
                break;
            }
        }  
        int n = YorN();
        if (n == 2 || n == 3) 
            save(&v_count, &l_count);
        if (n == 3 || n == 4) {
            printf("\n�� : %d��   �� : %d��\n", v_count, l_count);
            printf("<<<<���ھ߱��� �����մϴ�.>>>>\n");
            break;
        }
        free(answer);
        free(player);
        trial += 1;
    }
}