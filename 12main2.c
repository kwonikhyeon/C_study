#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int num;
	char name[20];
	int kor, eng, math;
	int tot;
	double avg;
	char grade;
}Student;

int cnt = 0;

void input_data(Student* array)
{
	for (int i = 0; i < cnt; i++)
	{
		printf("> �й� : ");
		scanf("%d", &(array[i].num));
		printf("> �̸� : ");
		scanf("%s", &(array[i].name));
		printf("> ����, ����, ���� ���� : ");
		scanf("%d %d %d", &(array[i].kor), &(array[i].eng), &(array[i].math));
		printf("--------------------------\n");
	}
}

void calc_data(Student* array)
{
	for (int i = 0; i < cnt; i++)
	{
		array[i].tot = array[i].kor + array[i].eng + array[i].math;
		array[i].avg = (array[i].kor + array[i].eng + array[i].math) / 3;
		if (array[i].avg >= 90)
			array[i].grade = 'A';
		else if (array[i].avg >= 80)
			array[i].grade = 'B';
		else if (array[i].avg >= 70)
			array[i].grade = 'C';
		else
			array[i].grade = 'F';
	}
}

void print_data(Student* array)
{
	for (int i = 0; i < cnt; i++)
		printf("%10d  %7s  %5d  %5d  %5d  %5d  %10.3f %3c\n", (array+i)->num, (array + i)->name, (array + i)->kor, (array + i)->eng, (array + i)->math, (array + i)->tot, (array + i)->avg, (array + i)->grade);
}

void struct_swap(Student* first, Student* second)
{
	Student temp; 
	temp = *first;
	*first = *second;
	*second = temp;
}

void selection_sort(Student* array)
{
	int min;
	for (int i = cnt; i > 1; i--)
	{
		min = 0;
		for (int j = 1; j < i; j++)
		{
			if (array[min].avg > array[j].avg)
				min = j;
			else if (array[min].avg == array[j].avg) //����� ���� �� �й������� ����
			{
				if (array[min].num < array[j].num)
					min = j;
			}
		}
		struct_swap(&array[min], &array[i - 1]);
	}
}

int main()
{	
	Student* s_array = NULL; 
	printf("�л� ���� �Է��� �ּ���. : ");
	scanf("%d", &cnt);
	printf("****************************\n");

	s_array = (Student*)malloc((sizeof(Student)) * cnt);

	input_data(s_array);
	calc_data(s_array);

	printf("## ���� �� ������ ##\n");
	print_data(s_array); 

	selection_sort(s_array); 

	printf("\n## ���� �� ������ ##\n");
	print_data(s_array);

	free(s_array);
	return 0;
}