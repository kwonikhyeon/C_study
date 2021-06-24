#include <stdio.h>
#include <stdlib.h>
//�л��������α׷�
//1.�߰� 2.���� 3.�˻� 4.���� 5.��� 6.����

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
	printf("������ �߰� �Ϸ�.\n\n");
	*cnt += 1;
}

void delete_node(Node* head, int num, int* cnt)
{
	Node* target = head;
	Node* temp = head;
	if (head->next == NULL)
	{
		printf("�����Ͱ� ������ϴ�.\n\n");
		return;
	}
	else
	{
		for (int i = 1; i < num ; i++)
			temp = temp->next;
		target = temp->next;
		temp->next = target->next;
		free(target);
		printf("%d ��° ������ ���� �Ϸ�.\n\n", num);
		*cnt -= 1;
	}
}

void node_search(Node* head, int code)
{
	Node* temp = head->next;
	if (temp == NULL)
	{
		printf("�����Ͱ� ������ϴ�.\n\n");
	}
	else
	{
		while (1)
		{
			if (temp == NULL)
			{
				printf("�ش� �й��� �����Ϳ� �����ϴ�.\n\n");
				break;
			}

			else if (temp->code_num == code)
			{
				printf("���� : %d  �й� : %d\n\n", temp->age, temp->code_num);
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
		printf("�����Ͱ� ����ֽ��ϴ�.\n");
		return 0;
	}
	printf("<<data_list>>\n\n");
	while (temp != NULL)
	{
		printf(" %d. ����:%d  �й�:%d\n", count, temp->age, temp->code_num);
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
		printf("�׸��� ��� ������ �� �����ϴ�.");
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
	
	if (s == 1)//��������
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
		printf("������������ ���ĵǾ����ϴ�.\n");
	}
	else if (s == 2)//��������
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
		printf("������������ ���ĵǾ����ϴ�.\n");
	}



	else
		printf("�߸��� ���Ĺ���Դϴ�.\n");
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
		printf("1.�߰� 2.���� 3.�˻� 4.���� 5.��� 6.����.\n");
		scanf("%d", &menu);
		switch (menu)
		{
		case 1:
			printf("<<�����͸� �Է����ּ���>>\n");
			printf("���� : ");
			scanf("%d", &a);
			printf("�й� : ");
			scanf("%d", &c);
			add_node(head, a, c, &count);
			break;
		case 2:
			printf("<<������ �������� ��ȣ�� �Է����ּ���>>\n");
			scanf("%d", &del_num);
			delete_node(head, del_num, &count);
			break;
		case 3:
			printf("<<�˻��� �й��� �Է����ּ���>>\n");
			printf("�й� : ");
			scanf("%d", &c);
			node_search(head, c);
			break;
		case 4:
			printf("<<���Ĺ���� �Է����ּ���>>\n");
			printf("(1)��������		(2)��������\n");
			printf("��� : ");
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