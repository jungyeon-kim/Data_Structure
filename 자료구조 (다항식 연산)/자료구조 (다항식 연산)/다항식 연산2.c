#include <stdio.h>
#define MAX 50
typedef struct {
	int degree; // 지수
	int coef[MAX]; // 계수
}polynomial;

polynomial multPoly(polynomial *A, polynomial *B);

polynomial input1() {

	int i = 0;
	int num = 0;
	polynomial A = { 0,{ 0, 0 } }; // 초기화

	printf("첫번째다항식의최대지수크기를입력: ");
	scanf_s("%d", &A.degree);//최대지수를입력받는다

	for (i = A.degree; i >= 0; i--) {
		printf("x^%d제곱의계수입력:", i);//최대지수에서1씩빼면서각지수의계수를입력받는다.
		scanf_s("%d", &A.coef[i]);
	}


	return A;//polynomial A로값을리턴해준다.
}
polynomial input2() {//두번째 다항식 값을 입력 받는 함수

	int i = 0;

	polynomial B = { 0,{ 0, 0 } }; // 초기화


	printf("두번째 다항식의 최대 지수 크기를 입력: ");
	scanf_s("%d", &B.degree);
	for (i = B.degree; i >= 0; i--) {
		printf("x^%d제곱의계수입력:", i);
		scanf_s("%d", &B.coef[i]);
	}

	return B;
}


polynomial multPoly(polynomial *A, polynomial *B) {//다항식을곱하는함수
	polynomial output = { 0 };
	int i, j, k;

	output.degree = (*A).degree + (*B).degree;

	for (i = 0; i <= (*A).degree; i++) {
		for (j = 0; j <= (*B).degree; j++) {
			for (k = 0; k <= output.degree; k++) {
				if ((i + j) == k) {
					output.coef[k] += (*A).coef[i] * (*B).coef[j];
				}
			}
		}
	}
	return output;
}
void printpoly(polynomial P) {//다항식을출력하는함수
	int i, degree;

	degree = P.degree;
	for (i = P.degree; i >= 0; i--) {
		if (P.coef[i] == 0) {
		}
		else {
			if (i == 0) printf("%d\n", P.coef[i]);//x^0의출력을막기위해지수가0(i가0일경우)이면숫자만출력한다.
			else {
				printf("%dx^%d", P.coef[i], i);//
				printf(" + ");
			}
		}
	}
}

void main() {
	polynomial A = input1();//input1의구조체polynomial정보를할당
	polynomial B = input2();//input1의구조체polynomial정보를할당

	polynomial C = multPoly(&A, &B);//둘을곱하는함수를써서연산내용을polynomial C에할당

	printf("\n A(x)=");
	printpoly(A);
	printf("\n B(x)=");
	printpoly(B);
	printf("\n C(x)=");
	printpoly(C);
	printf("\n\n");
}