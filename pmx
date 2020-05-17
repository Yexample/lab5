#include "pch.h"
#include <iostream>

extern int n;
extern char name1[90], name2[90];
extern FILE *f1, *f2;

void pmx() {
	int l, i, j;
	double** mx;
	printf("Введите имя файла с размерами матрицы : ");
	gets_s(name1);
	l = 1;
	if ((f1 = fopen(name1, "r")) == NULL) {
		while (l == 1) {
			if ((f1 = fopen(name1, "r")) == NULL) {
				printf("Файл не найден\n");
				printf("Введите имя файла с размерами матрицы : ");
				memset(&name1[0], 0, sizeof(name1));
				gets_s(name1);
			}
			else
			{
				l = 0;
			}

		}
	}
	fscanf(f1, "%i", &n);
	mx = new double*[n + 1];

	for (i = 1; i <= n; i++) {
		mx[i] = new double[n + 1];
	}
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			mx[i][j] = (abs(j - 3) - 1.3)*pow((6.5 - j), pow(2, (j - 1)))*(2 * abs(3.3 - i) - 1.5);
		}

	}
	printf("Введите для сохранения матрицы : ");
	gets_s(name2);
	f2 = fopen(name2, "w+");
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			fprintf(f2, "%lf ", mx[i][j]);
		}
		fprintf(f2, "\n");
	}

	for (i = 1; i <= n; i++)
		delete mx[i];
	delete[] mx;
	fcloseall;
	fclose(f2);
}

