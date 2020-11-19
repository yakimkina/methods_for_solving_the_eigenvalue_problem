#include "main.h"

/*
vector<vector<VALUE_TYPE>>	create_T(int size, int k, int l, VALUE_TYPE alpha, VALUE_TYPE beta)
{
	vector<vector<VALUE_TYPE>> T;

	for (int i = 0; i < size; i++)
	{
		vector<VALUE_TYPE> tmp;
		for (int j = 0; j < size; j++)
		{
			if ((i == k && j == k) || (i == l && j == l)) tmp.push_back(alpha);
			else if (i == k && j == l) tmp.push_back(beta);
			else if (i == l && j == k) tmp.push_back((-1) * beta);
			else if (i == j) tmp.push_back(1);
			else tmp.push_back(0);
		}

		T.push_back(tmp);
	}
	
	return (T);
}
*/

vector<vector<VALUE_TYPE>> 	to_Hessenberg_shape(vector<vector<VALUE_TYPE>> slae)
{
	int	size = slae.size();

	vector<vector<VALUE_TYPE>>	H(slae);

	for (int j = 0; j < (size - 2); j++)
	{
		for (int i = j + 2; i < size; i++)
		{
			int	l = i;
			int	k = j + 1;

			VALUE_TYPE	sq = sqrt(H[k][k - 1] * H[k][k - 1] + H[l][k - 1] * H[l][k - 1]);
			VALUE_TYPE	alpha = H[k][k - 1] / sq;
			VALUE_TYPE	beta = H[l][k - 1] / sq;

//			vector<vector<VALUE_TYPE>>	matT = create_T(size, k, l, alpha, beta);
//			vector<vector<VALUE_TYPE>>	matT_t = transpose(matT);

			for (int m = 0; m < size; m++)
			{
				VALUE_TYPE	x1 = H[k][m];
				VALUE_TYPE	x2 = H[l][m];
				H[k][m] = alpha * x1 + beta * x2;
				H[l][m] = (-1) * beta * x1 + alpha * x2;
			}

			for (int m = 0; m < size; m++)
			{
				VALUE_TYPE	x1 = H[m][k];
				VALUE_TYPE	x2 = H[m][l];
				H[m][k] = alpha * x1 + beta * x2;
				H[m][l] = (-1) * beta * x1 + alpha * x2;
			}
		}
	}

	return (H);
}