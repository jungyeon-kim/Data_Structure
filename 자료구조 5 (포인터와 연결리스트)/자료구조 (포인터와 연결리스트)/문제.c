#include<stdio.h>

//int main()
//{
//	int value = 10, *temp;
//	temp = &value;
//	*temp = 20;
//	printf("value = %d, *temp = %d\n", value, *temp);
//}

// ����
void swap(int *p1, int *p2)
{
	int *tmp;
	tmp = *p1; // ��Ÿ�� �Ⱥ��̸� ���縸 ��.
	*p1 = *p2;
	*p2 = tmp;
}
void main() {
	int x = 10;
	int y = 20;
	swap(&x, &y);
	printf("x = %d, y = %d \n", x, y);
}