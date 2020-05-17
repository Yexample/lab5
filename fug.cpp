#include "pch.h"
#include <iostream>
extern int n;
extern char name4[90], name3[90];
extern FILE *f3, *f4;
void fug() {
	int i;
	double *vc = new double[n + 1];
	double g = 0;
	fclose(f3);
	f3 = fopen(name3, "r");
	fseek(f3, 0, SEEK_SET);
	for (i = 1; i <= n; i++) {
		fscanf(f3, "%lf ", &vc[i]);
	}
		for (i = 1; i <= n; i++) {
			g = g + (vc[i] * vc[n - i + 1]);
		}
	
	printf("Введите имя файла для хранения g(x) : ");
	gets_s(name4);
	f4 = fopen(name4, "w");
	fprintf(f4, "g(x) = ");
	fprintf(f4, "%lf", g);
	delete vc;
	fcloseall;

}
