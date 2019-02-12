#include <stdio.h>

int main()
{
	int arr[9] = { 3, 2, 1, 6, 5, 4, 9, 8, 7 };
	int tmp;

	printf("기본정렬: ");
	for (int i = 0; i < 9; i++)
		printf("%d ", arr[i]);
	printf("\n");

	printf("역순: ");
	for (int i = 0; i < 4; i++)
	{
		tmp = arr[i];
		arr[i] = arr[8 - i];
		arr[8 - i] = tmp;
	}
	for (int i = 0; i < 9; i++)
		printf("%d ", arr[i]);
	printf("\n");

	printf("오름차순: ");
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	for (int i = 0; i < 9; i++)
		printf("%d ", arr[i]);
	printf("\n");

	printf("내림차순: ");
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
		{
			if (arr[j] < arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	for (int i = 0; i < 9; i++)
		printf("%d ", arr[i]);
	printf("\n");
}