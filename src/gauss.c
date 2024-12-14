#include "gauss.h"
#include <stdio.h>

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(MatrixPtr A, MatrixPtr b)
{
	int n = A->r;

	for (int k = 0; k < n; k++)
	{
		int max_row = k;
		for (int i = k + 1; i < n; i++)
		{
			if (A->data[i][k] > A->data[max_row][k])
			{
				max_row = i;
			}
		}

		if (max_row != k)
		{
			for (int j = k; j < n; j++)
			{
				double temp = A->data[k][j];
				A->data[k][j] = A->data[max_row][j];
				A->data[max_row][j] = temp;
			}
			double temp = b->data[k][0];
			b->data[k][0] = b->data[max_row][0];
			b->data[max_row][0] = temp;
		}

		for (int i = k + 1; i < n; i++)
		{
			if (A->data[i][k] != 0)
			{
				double factor = A->data[i][k] / A->data[k][k];

				for (int j = k; j < n; j++)
				{
					A->data[i][j] -= factor * A->data[k][j];
				}
				b->data[i][0] -= factor * b->data[k][0];
			}
		}
	}

	for (int k = 0; k < n; k++)
	{
		if (A->data[k][k] == 0)
		{
			return 1;
		}
		else if (A->data[k][k] != 1)
		{
			double temp = A->data[k][k];

			for (int j = k; j < n; j++)
			{
				A->data[k][j] = A->data[k][j] / temp;
			}

			b->data[k][0] = b->data[k][0] / temp;
		}
	}

	return 0;
}
