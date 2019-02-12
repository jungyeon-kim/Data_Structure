#include<stdio.h>

int command, n, *a;
int sum = 0;

int print()
{
	printf("==========================\n");
	printf("1.크기가 n인 동적 배열을 생성\n");
	printf("2.배열을 난수로 채운다.\n");
	printf("3.배열의 각 원소를 출력한다.\n");
	printf("4.배열의 각 원소들의 합을 출력한다.\n");
	printf("5.동적 할당 공간을 반납한다.\n");
	printf("==========================\n");
	return 0;
}

int MakeArr()
{
	if (command == 1)
	{
		printf("배열의 크기를 생성하세요: ");
		scanf_s("%d", &n);
	}
}

int MakeRandom()
{
	if (command == 2)
	{
		for (int i = 0; i < n; i++) {
			a[i] = rand() % 100;
		}
		printf("난수로 생성되었습니다. \n");
	}
}

int PrintRandom()
{
	if (command == 3)
	{
		printf("생성된 난수: ");
		for (int i = 0; i < n; i++) {
			printf("%d ", a[i]);
		}
		printf("\n");
	}
}

int Sum()
{
	for (int i = 0; i <n; i++)
	{
		sum += a[i];
	}
	printf("난수들의 합: %d \n", sum);
}

int init()
{
	free(a);
	printf("메모리를 반납했습니다. \n");
}

int main()
{
	print();

	while (1)
	{
		scanf_s("%d", &command);
		switch (command)
		{
		case 1:
			MakeArr();
			a = (int*)malloc(sizeof(int)*n);
			break;
		case 2:
			MakeRandom();
			break;
		case 3:
			PrintRandom();
			break;
		case 4:
			Sum();
			break;
		case 5:
			init();
			break;
		}
	}
}