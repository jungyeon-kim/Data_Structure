#include<stdio.h>

int command, n, *a;
int sum = 0;

int print()
{
	printf("==========================\n");
	printf("1.ũ�Ⱑ n�� ���� �迭�� ����\n");
	printf("2.�迭�� ������ ä���.\n");
	printf("3.�迭�� �� ���Ҹ� ����Ѵ�.\n");
	printf("4.�迭�� �� ���ҵ��� ���� ����Ѵ�.\n");
	printf("5.���� �Ҵ� ������ �ݳ��Ѵ�.\n");
	printf("==========================\n");
	return 0;
}

int MakeArr()
{
	if (command == 1)
	{
		printf("�迭�� ũ�⸦ �����ϼ���: ");
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
		printf("������ �����Ǿ����ϴ�. \n");
	}
}

int PrintRandom()
{
	if (command == 3)
	{
		printf("������ ����: ");
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
	printf("�������� ��: %d \n", sum);
}

int init()
{
	free(a);
	printf("�޸𸮸� �ݳ��߽��ϴ�. \n");
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