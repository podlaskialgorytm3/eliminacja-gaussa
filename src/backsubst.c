#include "backsubst.h"
#include <stdio.h>

/**
 * Funkcja wykonuje wsteczne podstawienie w celu rozwiązania układu równań liniowych.
 * Zwraca 0 - wsteczne podstawienie zakończone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int backsubst(MatrixPtr x, MatrixPtr A, MatrixPtr b)
{
	if (A->r != A->c || A->r != b->r || b->c != 1 || x->r != b->r || x->c != 1)
	{
		return 2;
	}

	int n = A->r;

	for (int i = n - 1; i >= 0; i--)
	{

		if (A->data[i][i] == 0.0)
		{
			return 1;
		}

		double sum = 0.0;
		for (int j = i + 1; j < n; j++)
		{
			sum += A->data[i][j] * x->data[j][0];
		}
		x->data[i][0] = (b->data[i][0] - sum) / A->data[i][i];
	}

	return 0;
}
