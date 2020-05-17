#include "pch.h"
#include <iostream>

extern int n;
extern char name3[90], name2[90];
extern FILE *f3, *f2;

void vect() {
	double** mx;
	int i, j, jj, ii;
	double minv;
	fcloseall;
	fclose(f2);
	mx = new double*[n + 1];

	for (i = 1; i <= n; i++) {
		mx[i] = new double[n + 1];
	}
	f2 = fopen(name2, "r");
	/////////////////////////////////////////////////////////////////
	int count_space = 0, count = 0, nn, mm;

	//fseek(f2, 0, SEEK_SET);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			fscanf(f2, "%lf ", &mx[i][j]);
		}
	}
	////////////////////////////////////////////////////////////////////
	double *vc = new double[n + 1];
	int mini, minj;
	minv = mx[1][1];
	int s = 1;
	if (n > 1) {
		for (i = 2; i <= n; i++) {
			for (j = 2; j <= n; j++) {
				if (mx[i][j] <= minv) {
					minv = mx[i][j];
					mini = i;
					minj = j;
					for (ii = mini; ii <= n; ii++) {
						for (jj = minj; jj <= n; jj++) {
							vc[s] = mx[mini][jj] * mx[ii][minj];
						}
					}
					j = n + 1;
				}
				else
				{
					for (ii = 1; ii <= n; ii++) {
						for (jj = 1; jj <= n; jj++) {
							vc[s] = mx[1][jj] * mx[ii][1];
						}
					}
					j = n + 1;
				}
			}
			s++;
		}
	}
	else vc[1] = minv;

	printf("Введите имя файла для хранения вектора X : ");
	gets_s(name3);
	f3 = fopen(name3, "w");
	//fprintf(f3, "X : \n");
	for (i = 1; i <= n; i++) {
		fprintf(f3, "%lf ", vc[i]);
	}
	for (int i = 1; i <= n; i++)
		delete mx[i];
	delete[] mx;
	delete vc;
	fcloseall;
}
