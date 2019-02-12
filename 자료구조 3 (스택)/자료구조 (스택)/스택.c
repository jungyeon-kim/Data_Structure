#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

//#define MAX_SIZE 100
//
//void push(int input);
//int pop();
//void print();
//
//char stack[MAX_SIZE]; // 스택 배열 생성
//int top = -1; // 스택의 가장 마지막 데이터 위치
//
//int main()
//{
//	for (int i = 1; i < 10; i++)
//		push(i);
//	printf("스택 push 9회 \n");
//	printf("pop() --> %d\n", pop());
//	printf("pop() --> %d\n", pop());
//	printf("pop() --> %d\n", pop());
//	printf("스택 pop 3회\n");
//
//	return 0;
//}
//
//void push(int input)
//{
//	if (top >= (MAX_SIZE - 1)) // 스택이 가득차면 삽입 불가
//		return;
//	stack[++top] = input; // 스택에 input 데이터 삽입
//}
//
//int pop()
//{
//	return stack[top--];
//}
//
//void print()
//{
//	// 스택 전체를 출력
//	for (int i = 0; i <= top; i++)
//		printf("%d ", stack[i]);
//}


//#define max_stack_size 100
//
//typedef int element;
//element data[max_stack_size];
//int top;
//
//void error(char str[])
//{
//	printf("%s\n", str);
//	exit(1);
//}
//
//void init_stack() { top = -1; }
//int size() { return top + 1; }
//int is_full() { return (top == max_stack_size - 1); }
//int is_empty() { return (top == -1); }
//
//void push(element e)
//{
//	if (is_full())
//		error("스택 포화 에러");
//	data[++top] = e;
//}
//
//element pop()
//{
//	if (is_empty())
//		error("스택 공백 에러");
//	return data[top--];
//}
//
//element peek()
//{
//	if (is_empty())
//		error("스택 공백 에러");
//	return data[top];
//}
//
//void print_stack(char msg[])
//{
//	int i;
//	printf("%s[%d]= ", msg, size());
//	for (i = 0; i<size(); i++)
//		printf("%d ", data[i]);
//	printf("\n");
//}
//
//void main()
//{
//	int i;
//	init_stack();
//	for (i = 1; i<10; i++)
//		push(i);
//	print_stack("스택 push 9회");
//	printf("\tpop() --> %d\n", pop());
//	printf("\tpop() --> %d\n", pop());
//	printf("\tpop() --> %d\n", pop());
//	print_stack("스택 pop 3회");
//}
//

// 중위 > 후위 > 중위

static int precedence(char op) {
	switch (op) {
	case '(': case ')': return 0;
	case '+': case '‐': return 1;
	case '*': case '/': return 2;
	}
	return -1;
}
void infix_to_postfix(char expr[]) { ... }
void main()
{
	char expr[2][80] = { "8/2‐3+(3*2)", "1/2* 4 * (1/4)" };
	printf("중위수식: %s ==> 후위수식:", expr[0]);
	infix_to_postfix(expr[0]);
	printf("중위수식: %s ==> 후위수식:", expr[1]);
	infix_to_postfix(expr[1]);
}
