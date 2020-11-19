#include "main.h"

bool	is_degenerate(vector<vector<VALUE_TYPE>> &slae, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (abs(slae[i][i]) < EPSILON)
			return true;
	}

	return false;
}

