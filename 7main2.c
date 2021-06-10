#include <stdio.h>

void swap(int* p1, int* p2)//���� �Լ�
{
	int temp;
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

void view(int* p, int n)//�迭 �����ִ� �Լ�
{
	for (int a = 0; a < n; a++)
	{
		printf("%d ", *(p + a));
	}
	printf("\n");
}


int main()
{
	int s[10];
	int i, j, n, m;
	int* ptr;

	ptr = s;
	
	printf("�迭�� ä���ּ���(���� 10��)\n");
	for (i = 0; i < 10; i++)
	{
		printf("s[%d]�� ������ : ", i);
		scanf("%d", &n);
		s[i] = n;
	}

	printf("���Ĺ���� �������ּ���(1 : ��������  2 : ��������)\n");
	printf("==>");
	scanf("%d", &m);

	if ((m != 1) && (m != 2))
	{
		printf("���� �׸��Դϴ�. 1 �Ǵ� 2�� �����ؾ� �մϴ�. ���α׷��� �����մϴ�.");
		return 0;
	}
	
	printf("���� �� �迭 s ==> ");
	view(ptr, sizeof(s) / sizeof(int));

	switch (m)
	{
	case 1://��������
		for (i = 0; i < 9; i++)
		{
			for (j = i + 1; j < 10; j++)
			{
				if (*(ptr + i) > *(ptr + j))
				{
					swap(ptr + i, ptr + j);
				}
			}
		}
		break;
	case 2://��������
		for (i = 0; i < 9; i++)
		{
			for (j = i + 1; j < 10; j++)
			{
				if (*(ptr + i) < *(ptr + j))
				{
					swap(ptr + i, ptr + j);
				}
			}
		}
		break;
	}

	printf("���� �� �迭 s ==> ");
	view(ptr, sizeof(s) / sizeof(int));

	return 0;
}