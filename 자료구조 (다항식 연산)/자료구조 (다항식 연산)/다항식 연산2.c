#include <stdio.h>
#define MAX 50
typedef struct {
	int degree; // ����
	int coef[MAX]; // ���
}polynomial;

polynomial multPoly(polynomial *A, polynomial *B);

polynomial input1() {

	int i = 0;
	int num = 0;
	polynomial A = { 0,{ 0, 0 } }; // �ʱ�ȭ

	printf("ù��°���׽����ִ�����ũ�⸦�Է�: ");
	scanf_s("%d", &A.degree);//�ִ��������Է¹޴´�

	for (i = A.degree; i >= 0; i--) {
		printf("x^%d�����ǰ���Է�:", i);//�ִ���������1�����鼭�������ǰ�����Է¹޴´�.
		scanf_s("%d", &A.coef[i]);
	}


	return A;//polynomial A�ΰ����������ش�.
}
polynomial input2() {//�ι�° ���׽� ���� �Է� �޴� �Լ�

	int i = 0;

	polynomial B = { 0,{ 0, 0 } }; // �ʱ�ȭ


	printf("�ι�° ���׽��� �ִ� ���� ũ�⸦ �Է�: ");
	scanf_s("%d", &B.degree);
	for (i = B.degree; i >= 0; i--) {
		printf("x^%d�����ǰ���Է�:", i);
		scanf_s("%d", &B.coef[i]);
	}

	return B;
}


polynomial multPoly(polynomial *A, polynomial *B) {//���׽������ϴ��Լ�
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
void printpoly(polynomial P) {//���׽�������ϴ��Լ�
	int i, degree;

	degree = P.degree;
	for (i = P.degree; i >= 0; i--) {
		if (P.coef[i] == 0) {
		}
		else {
			if (i == 0) printf("%d\n", P.coef[i]);//x^0���������������������0(i��0�ϰ��)�̸���ڸ�����Ѵ�.
			else {
				printf("%dx^%d", P.coef[i], i);//
				printf(" + ");
			}
		}
	}
}

void main() {
	polynomial A = input1();//input1�Ǳ���üpolynomial�������Ҵ�
	polynomial B = input2();//input1�Ǳ���üpolynomial�������Ҵ�

	polynomial C = multPoly(&A, &B);//�������ϴ��Լ����Ἥ���곻����polynomial C���Ҵ�

	printf("\n A(x)=");
	printpoly(A);
	printf("\n B(x)=");
	printpoly(B);
	printf("\n C(x)=");
	printpoly(C);
	printf("\n\n");
}