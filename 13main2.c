#include <stdio.h>
#include <stdlib.h>
#include "point.h"
#include "line.h"
#define AVR(X,Y) (X+Y)/2;

int main(int argc, char* argv[])
{
	if (argc != 5)
	{
		printf("\n__�Ű������� 4�� ����ϼ���__\n");
		return 0;
	}
	
	Line a;
	Point b;

	a.first.x = atoi(argv[1]);
	a.first.y = atoi(argv[2]);
	a.second.x = atoi(argv[3]);
	a.second.y = atoi(argv[4]);


	b.x = AVR(a.first.x, a.second.x);
	b.y = AVR(a.first.y, a.second.y);

	printf("���� ��� �� ��ǥ : {%d, %d}\n", b.x, b.y);
	return 0;
}