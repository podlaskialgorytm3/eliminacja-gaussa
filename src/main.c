#include "gauss.h"
#include "backsubst.h"
#include "mat_io.h"
#include <stdlib.h>
#include <stdio.h>

void checkCorrectly(int res)
{
	if (res == 1)
	{
		printf("Wykonano operacje dzielenia przez 0!");
		exit(1);
	}
	else if (res == 2)
	{
		printf("Nieprawidlowy rozmiar macierzy!");
		exit(1);
	}
}

int main(int argc, char **argv)
{
	int res;
	MatrixPtr A = readFromFile(argv[1]);
	MatrixPtr b = readFromFile(argv[2]);
	MatrixPtr x;

	if (A == NULL)
		return -1;
	if (b == NULL)
		return -2;
	printToScreen(A);
	printToScreen(b);

	res = eliminate(A, b);
	checkCorrectly(res);

	x = createMatrix(b->r, 1);
	if (x != NULL)
	{
		res = backsubst(x, A, b);
		checkCorrectly(res);

		printToScreen(x);
		freeMatrix(x);
	}
	else
	{
		fprintf(stderr, "Błąd! Nie mogłem utworzyć wektora wynikowego x.\n");
	}

	freeMatrix(A);
	freeMatrix(b);

	return 0;
}