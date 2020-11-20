#include "main.h"

vector<VALUE_TYPE>	normalization(vector<VALUE_TYPE> &x, int size)
{
	VALUE_TYPE	norm = vector_norm(x, size);

	for (int i = 0; i < size; i++)
		x[i] /= norm;

	return x;
}

