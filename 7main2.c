#include <stdio.h>

void swap(int* p1, int* p2)//스왑 함수
{
	int temp;
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

void view(int* p, int n)//배열 보여주는 함수
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
	
	printf("배열을 채워주세요(숫자 10개)\n");
	for (i = 0; i < 10; i++)
	{
		printf("s[%d]의 데이터 : ", i);
		scanf("%d", &n);
		s[i] = n;
	}

	printf("정렬방식을 선택해주세요(1 : 오름차순  2 : 내림차순)\n");
	printf("==>");
	scanf("%d", &m);

	if ((m != 1) && (m != 2))
	{
		printf("없는 항목입니다. 1 또는 2를 선택해야 합니다. 프로그램을 종료합니다.");
		return 0;
	}
	
	printf("정렬 전 배열 s ==> ");
	view(ptr, sizeof(s) / sizeof(int));

	switch (m)
	{
	case 1://오름차순
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
	case 2://내림차순
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

	printf("정렬 후 배열 s ==> ");
	view(ptr, sizeof(s) / sizeof(int));

	return 0;
}