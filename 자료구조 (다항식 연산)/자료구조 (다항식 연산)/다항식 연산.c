#include<stdio.h>
#define MAX_DEGREE 101

typedef struct // ����ü
{
	int degree; // �ִ� ����

	float coef[MAX_DEGREE]; // ���

}Polynomial;

Polynomial sub_poly(Polynomial a, Polynomial b)
{

	int i;
	Polynomial p;
	{
		p = a;
		for (i = 0; i <= b.degree; i++)
			p.coef[i + (p.degree - b.degree)] -= b.coef[i]; // (p.degree - b.degree) ������ ��ġ ã��
	}

	return p;
}

Polynomial mult_poly(Polynomial a, Polynomial b) 
{
	Polynomial output = { 0 };
	int i, j, k;

	output.degree = a.degree + b.degree;

	for (i = 0; i <= a.degree; i++) {
		for (j = 0; j <= b.degree; j++) {
			for (k = 0; k <= output.degree; k++) {
				if ((i + j) == k) {
					output.coef[k] += a.coef[i] * b.coef[j];
				}
			}
		}
	}
	return output;
}

Polynomial read_poly() {
	int i;
	Polynomial p;

	printf("���׽��� �ְ� ���� �Է�:");
	scanf_s("%d", &p.degree);
	printf("�� ���� ��� �Է�(�� %d��)", p.degree + 1);

	for (i = 0; i <= p.degree; i++)
		scanf_s("%f", p.coef + i); // ����� ����(������)���� ��µǰ� ��.

	return p;
}

void print_poly(Polynomial p, char str[])
{
	int i;
	printf("\t%s", str); // \t = tapŰ, %s = ���ڿ� ���
	for (i = 0; i < p.degree; i++)
	{
		if (p.coef[i] == 1)
		{
			printf("x^%d + ", p.degree - i); // �ְ� �������� ���
		}
		else if (p.coef[i] == -1)
		{
			printf("- x^%d + ", p.degree - i);
		}
		else if (p.coef[i] == 0)
		{
		}
		else
			printf("%5.1f x^%d + ", p.coef[i], p.degree - i);
	}
	printf("%4.1f\n", p.coef[p.degree]);
}

void trim_Poly(Polynomial* p) {
	while (1) {
		int i;
		if (p->coef[0] == 0) {
			for (i = 0; i < p->degree; i++) {
				p->coef[i] = p->coef[i + 1];
			}
			--(p->degree);
		}
		else
			break;
	}
}

void main()
{
	Polynomial a, b, c, d;
	a = read_poly();
	b = read_poly();
	c = sub_poly(a, b);
	d = mult_poly(a, b);

	trim_Poly(&a);
	trim_Poly(&b);
	trim_Poly(&c);
	trim_Poly(&d);

	print_poly(a, "A = ");
	print_poly(b, "B = ");
	print_poly(c, "A - B = ");
	print_poly(d, "A * B = ");
}