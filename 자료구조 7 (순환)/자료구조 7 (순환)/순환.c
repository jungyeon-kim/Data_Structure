#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

int num;
int arr[MAX_SIZE] = { 0 };
int count[MAX_SIZE] = { 0 };
char tmp[MAX_SIZE] = { 0 };

// 합
int sum(int n)
{
	printf("%d\n", n);
	if (n < 1) return 0; // 끝내기
	else
		return (n + sum(n - 1)); // 재귀(순환)
}

// 별찍기
void asterisk(int i)
{
	if (i > 1) {
		asterisk(i / 2);
		asterisk(i / 2);
	}
	printf("*");
	printf("\n");
}

// 팩토리얼
int factorial(int n)
{
	if (n < 1) return 1;
	else
		return n * factorial(n - 1);
}

// 피보나치
int fib(int arr)
{
	for (int i = 0; i <= num; i++)
		if (arr == i)
			count[i]++;
	if (arr == 0) return 0;
	if (arr == 1) return 1;
	return (fib(arr - 1) + fib(arr - 2));
}

// 하노이탑
void hanoiTower(int n, char from, char tmp, char to)
{
	if (n == 1) printf("원판 1을 %c에서 %c으로 옮긴다.\n", from, to);
	else {
		hanoiTower(n - 1, from, to, tmp);
		printf("원판 %d을 %c에서 %c으로 옮긴다.\n", n, from, to);
		hanoiTower(n - 1, tmp, from, to);
	}
}

int main()
{
	//sum(5);
	//asterisk(5);
	//printf("%d", sum(5));
	//printf("%d", factorial(5));

	/*scanf_s("%d", &num);
	printf("합: %d\n", fib(num));
	for (int i = num; i >= 0; i--)
		printf("%d = %d번\n", i, count[i]);*/

	//hanoiTower(4, 'A', 'B', 'C');
	
	return 0;
}