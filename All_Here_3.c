#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <locale.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdbool.h>
#define _CRT_SECURE_NO_WARNINGS
#define Sym_count_f3 256
#define Sym_count_f4 20

void f1() {
	double S, p, n, r, m;
	printf("������� S, p � n:\n");
	scanf_s("%lf%lf%lf", &S, &p, &n);
	r = p / 100;
	m = S * r * pow((1 + r), n) / (12 * (pow((1 + r), n) - 1));
	printf("�������� ����� = %lf.\n", m);
}

void f2() {
	double S, p = 0, n, r, m, m_guess = 0;
	int k;
	printf("������� S, m � n:\n");
	scanf_s("%lf%lf%lf", &S, &m, &n);
	if (m <= pow(10, 4)) // ��� ������ �������, ��� ������ �����������
	{
		k = 1;
	}
	else if (m <= pow(10, 8))
	{
		k = 10;
	}
	else
	{
		k = 100;
	}
	if (m * n * 12 < S)
	{
		printf("������� ����� ����������.\n");
	}
	else
	{
		while (fabs(m_guess - m) >= k) // ���� ������������, ���� ������� ����� �������������� �������� � ������ �� ���. �������� >= �����������
		{
			p += 0.0001;
			r = p / 100;
			m_guess = S * r * pow((1 + r), n) / (12 * (pow((1 + r), n) - 1));
		}
		printf("C���� ��������� %.1lf , ������� ������� ��������� ��������� ��������� %.1lf � ������� %.0lf ���, ������ ��� ������� %.4lf *� ��������� �� 0.0001%.\n", S, m, n, p);
	}
	
}


int f3() {
	FILE* myfile;
	myfile = fopen("All_Here_3_3.txt", "w");	
	// FILE - ���������, ������ ���� �����. ���-��� ���������� �-�� fopen (�����. ���� �������� ����)
	//"r+" - ��������� ���� ��� ������/������
	//"w+" - ������� ���� ��� ������/������
	//"a+" - ���������� ���������� � ����� ����� ��� ������� ���� ��� ������/������	
	for (size_t i = (int)'A'; i < (26 + (int)'A'); i++)
	{
		fputc((char)i, myfile);
		fprintf(myfile, " = %d\n", i);
	}
	fclose(myfile);
	myfile = fopen("All_Here_3_3.txt", "r");
	if (myfile == NULL)
	{
		printf("���� %s �� ������.\n", myfile);
		return 0;
	}
	char mass[Sym_count_f3];
	while (fgets(mass, sizeof(mass), myfile))
	{
		printf("%s", mass);
	}
	printf("\n");
	fclose(myfile);
	return 0;
}

int f4() {
	printf("\n");
	FILE* myfile;
	myfile = fopen("All_Here_3_4.txt", "w");
	for (size_t i = (int) 'A'; i < (int) 'z'; i++)
	{
		fputc((char)i, myfile);
		fprintf(myfile, " - %d\n", i + 1 - (int)'A');
	}
	fclose(myfile);
	myfile = fopen("All_Here_3_4.txt", "r");
	printf("�������� ����:\n");
	if (myfile == NULL)
	{
		printf("���� %s �� ������.\n", myfile);
		return 0;
	}
	char mass[Sym_count_f3];
	while (fgets(mass, sizeof(mass), myfile))
	{
		printf("%s", mass);
	}
	fclose(myfile);
	myfile = fopen("All_Here_3_4.txt", "r");
	printf("\n��� ����� �����:\n");
	char sym;
	sym = fgetc(myfile);
	while (sym != EOF)
	{
		if (sym >= '0' && sym <= '9')
		{
			printf("%c", sym);
		}
		else if (sym == '\n')
		{
			printf(" ");
		}
		sym = fgetc(myfile);
	}
	printf("\n\n");
	fclose(myfile);
	return 0;
}

void quicksort(int l, int h) {
	int low = l, high = h;
	int pivot = (mass[low] + mass[high]) / 2; //����� ��.����. ����� ��������� � �������� ��. ��������, �.�. ��������� �������� ������
	// int pivot = mass[(low + high) / 2] - �������� �������� �������� ��� �������� (�� ����� �����������)
	while (low < high)
	{
		while (mass[low] < pivot)
		{
			low++;
		}
		while (mass[high] > pivot)
		{
			high--;
		}
		if (low <= high)
		{
			swap(mass[low++], mass[high--]);
		}
	}
	if (l < high)
	{
		quicksort(l, high);
	}
	if (h > low)
	{
		quicksort(low, h);
	}
}

void f5() {
	int mass[Sym_count_f4];
	for (int i = 0; i < Sym_count_f4; i++)
	{
		(*mass + i) = srand(time(NULL));
	}
}

int main() {
	int counter;
	setlocale(LC_ALL, "Russian");
	printf("����� ������ �� ��������� 5.\n����� ��������� ������, ������� 0.\n");
	printf("������� ����� ������: \n");
	scanf_s("%d", &counter);
	while (counter > 0)
	{
		switch (counter)
		{
		case 1:
			f1();
			break;
		case 2:
			f2();
			break;
		case 3:
			f3();
			break;
		case 4:
			f4();
			break;
		case 5:
			f5();
			break;
		default:
			printf("����� ������ �� ��������� 5.\n����� ��������� ������, ������� 0.\n");
			break;
		}
		printf("������� ����� ��������� ������: \n");
		scanf_s("%d", &counter);
	}
}