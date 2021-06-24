#include <stdio.h>
#include <stdlib.h>
//학생관리프로그램
//1.추가 2.삭제 3.검색 4.정렬 5.출력 6.종료

typedef struct creat_node
{
	struct creat_node* next;
	int age, code_num;
}Node;


void add_node(Node* head, int s_age, int s_code_num, int* cnt)
{
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->age = s_age;
	new_node->code_num = s_code_num;
	new_node->next = head->next;
	head->next = new_node;
	printf("데이터 추가 완료.\n\n");
	*cnt += 1;
}

void delete_node(Node* head, int num, int* cnt)
{
	Node* target = head;
	Node* temp = head;
	if (head->next == NULL)
	{
		printf("데이터가 비었습니다.\n\n");
		return;
	}
	else
	{
		for (int i = 1; i < num ; i++)
			temp = temp->next;
		target = temp->next;
		temp->next = target->next;
		free(target);
		printf("%d 번째 데이터 삭제 완료.\n\n", num);
		*cnt -= 1;
	}
}

void node_search(Node* head, int code)
{
	Node* temp = head->next;
	if (temp == NULL)
	{
		printf("데이터가 비었습니다.\n\n");
	}
	else
	{
		while (1)
		{
			if (temp == NULL)
			{
				printf("해당 학번이 데이터에 없습니다.\n\n");
				break;
			}

			else if (temp->code_num == code)
			{
				printf("나이 : %d  학번 : %d\n\n", temp->age, temp->code_num);
				break;
			}
			temp = temp->next;
		}
	}
}

void node_print(Node* head)
{
	Node* temp = head->next;
	int count = 1;
	if (temp == NULL)
	{
		printf("데이터가 비어있습니다.\n");
		return 0;
	}
	printf("<<data_list>>\n\n");
	while (temp != NULL)
	{
		printf(" %d. 나이:%d  학번:%d\n", count, temp->age, temp->code_num);
		temp = temp->next;
		count += 1;
	}
	printf("\n");
}

void node_swap(Node* one, Node* two)
{
	Node* temp;
	temp = one;
	one = two;
	two = temp;
}

void sort(Node* head, int s, int cnt)
{
	if (cnt == 0)
	{
		printf("항목이 없어서 정렬할 수 없습니다.");
		return;
	}
	
	Node* temp = head, * target = head;
	Node* min;
	Node** arr;
	arr = (Node**)malloc(sizeof(Node) * cnt);

	for (int i = 0; i < cnt; i++)
	{
		arr[i] = temp;
		temp = temp->next;
	}
	
	if (s == 1)//오름차순
	{
		for (int i = 0; i < cnt - 1; i++)
		{
			min = arr[i];
			for (int j = i + 1; j < cnt; j++)
			{
				if (min->code_num > arr[j]->code_num)
					min = arr[j];
			}
			node_swap(arr[i], min);
		}
		printf("오름차순으로 정렬되었습니다.\n");
	}
	else if (s == 2)//내림차순
	{
		for (int i = 0; i < cnt - 1; i++)
		{
			min = arr[i];
			for (int j = i + 1; j < cnt; j++)
			{
				if (min->code_num < arr[j]->code_num)
					min = arr[j];
			}
			node_swap(arr[i], min);
		}
		printf("내림차순으로 정렬되었습니다.\n");
	}



	else
		printf("잘못된 정렬방식입니다.\n");
	free(arr);
}

void all_free(Node* head)
{
	if (head->next == NULL)
		free(head);
	else
		all_free(head->next);
}

int main()
{
	int a, c, s, del_num, menu = 0;
	int count = 0;
	Node* head = (Node*)malloc(sizeof(Node));
	head->next = NULL;

	
	while (menu != 6)
	{
		printf("1.추가 2.삭제 3.검색 4.정렬 5.출력 6.종료.\n");
		scanf("%d", &menu);
		switch (menu)
		{
		case 1:
			printf("<<데이터를 입력해주세요>>\n");
			printf("나이 : ");
			scanf("%d", &a);
			printf("학번 : ");
			scanf("%d", &c);
			add_node(head, a, c, &count);
			break;
		case 2:
			printf("<<삭제할 데이터의 번호를 입력해주세요>>\n");
			scanf("%d", &del_num);
			delete_node(head, del_num, &count);
			break;
		case 3:
			printf("<<검색할 학번을 입력해주세요>>\n");
			printf("학번 : ");
			scanf("%d", &c);
			node_search(head, c);
			break;
		case 4:
			printf("<<정렬방식을 입력해주세요>>\n");
			printf("(1)오름차순		(2)내림차순\n");
			printf("방식 : ");
			scanf("%d", &s);
			sort(head, s, count);
			break;
		case 5:
			node_print(head);
			break;
		}
	}
	
	all_free(head);
	
	return 0;
}