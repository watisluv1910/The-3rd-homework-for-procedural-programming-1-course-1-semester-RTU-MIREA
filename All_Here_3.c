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
	printf("Введите S, p и n:\n");
	scanf_s("%lf%lf%lf", &S, &p, &n);
	r = p / 100;
	m = S * r * pow((1 + r), n) / (12 * (pow((1 + r), n) - 1));
	printf("Месячная плата = %lf.\n", m);
}

void f2() {
	double S, p = 0, n, r, m, m_guess = 0;
	int k;
	printf("Введите S, m и n:\n");
	scanf_s("%lf%lf%lf", &S, &m, &n);
	if (m <= pow(10, 4)) // Чем больше выплата, тем больше погрешность
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
		printf("Выплата ссуды невозможна.\n");
	}
	else
	{
		while (fabs(m_guess - m) >= k) // Цикл продолжается, пока разница между предполагаемой выплатой и данной по усл. выплатой >= погрешности
		{
			p += 0.0001;
			r = p / 100;
			m_guess = S * r * pow((1 + r), n) / (12 * (pow((1 + r), n) - 1));
		}
		printf("Cумма величиной %.1lf , которая гасится месячными выплатами величиной %.1lf в течение %.0lf лет, выдана под процент %.4lf *с точностью до 0.0001%.\n", S, m, n, p);
	}
	
}


int f3() {
	FILE* myfile;
	myfile = fopen("All_Here_3_3.txt", "w");	
	// FILE - указатель, внутрь него помещ. рез-тат выполнения ф-ии fopen (возвр. весь открытый файл)
	//"r+" - Открывает файл для чтения/записи
	//"w+" - Создает файл для чтения/записи
	//"a+" - Дописывает информацию к концу файла или создает файл для чтения/записи	
	for (size_t i = (int)'A'; i < (26 + (int)'A'); i++)
	{
		fputc((char)i, myfile);
		fprintf(myfile, " = %d\n", i);
	}
	fclose(myfile);
	myfile = fopen("All_Here_3_3.txt", "r");
	if (myfile == NULL)
	{
		printf("Файл %s не найден.\n", myfile);
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
	printf("Исходный файл:\n");
	if (myfile == NULL)
	{
		printf("Файл %s не найден.\n", myfile);
		return 0;
	}
	char mass[Sym_count_f3];
	while (fgets(mass, sizeof(mass), myfile))
	{
		printf("%s", mass);
	}
	fclose(myfile);
	myfile = fopen("All_Here_3_4.txt", "r");
	printf("\nВсе числа файла:\n");
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
	int pivot = (mass[low] + mass[high]) / 2; //Выбор ср.знач. между начальным и конечным эл. логичнее, т.к. позволяет избежать ошибок
	// int pivot = mass[(low + high) / 2] - Введение опорного элемента как среднего (не самый оптимальный)
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
	printf("Номер задачи не превышает 5.\nЧтобы закончить работу, введите 0.\n");
	printf("Введите номер задачи: \n");
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
			printf("Номер задачи не превышает 5.\nЧтобы закончить работу, введите 0.\n");
			break;
		}
		printf("Введите номер следующей задачи: \n");
		scanf_s("%d", &counter);
	}
}