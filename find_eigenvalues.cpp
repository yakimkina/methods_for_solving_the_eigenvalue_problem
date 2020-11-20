#include "main.h"

bool 	not_all_zero_under_diagonal(vector<vector<VALUE_TYPE>> &slae, int size)
{
	for (int i = 1; i < size; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (abs(slae[i][j]) > EPSILON)
				return true;
		}
	}
	
	return false;
}

vector<VALUE_TYPE>		find_eigenvalues(vector<vector<VALUE_TYPE>> slae)
{
	int	size = slae.size();

	int i = 1;
	while (not_all_zero_under_diagonal(slae, size))
	{
		QR sol = QR_method(slae, size);

		slae = multiply(sol.R, sol.Q, slae.size(), 1);

		cout << endl << MAGENTA << "A(" << i << "):" << RESET << endl;
		print_slae(slae, slae.size());
		i += 1;
	}
	cout << endl << GREEN << "#########################" << RESET << endl;

	vector<VALUE_TYPE>	eigenvalues;
	for (int i = 0; i < size; i++)
		eigenvalues.push_back(slae[i][i]);

	return eigenvalues;
}

void 	shift_slae(vector<vector<VALUE_TYPE>> &slae, int n, VALUE_TYPE sigma)
{
	for (int i = 0; i < n; i++)
		slae[i][i] -= sigma;
}

void 	unshift_slae(vector<vector<VALUE_TYPE>> &slae, int n, VALUE_TYPE sigma)
{
	for (int i = 0; i < n; i++)
		slae[i][i] += sigma;
}

bool 	not_all_zero_in_n_row(vector<vector<VALUE_TYPE>> &slae, int row)
{
	for (int i = 0; i < row; i++)
	{
		if (abs(slae[row][i]) > EPSILON)
			return true;
	}

	return false;
}

vector<VALUE_TYPE>		find_eigenvalues_with_shift(vector<vector<VALUE_TYPE>> slae)
{
	vector<VALUE_TYPE>	eigenvalues;
	int	size = slae.size();

	int i = 1;
	int n = size - 1;
	VALUE_TYPE	sigma = slae[n][n];

	while (n > 0)
	{
		shift_slae(slae, n + 1, sigma);

		while (not_all_zero_in_n_row(slae, n))
		{
			QR sol = QR_method(slae, n + 1);
			slae = multiply(sol.R, sol.Q, n + 1, 1);
			
			cout << endl << MAGENTA << "A(" << i << "):" << RESET << endl;
			print_slae(slae, slae.size());
			i += 1;
		}

		unshift_slae(slae, n + 1, sigma);

		eigenvalues.push_back(slae[n][n]);
		n -= 1;
		sigma = slae[n][n];

	}
	cout << endl << GREEN << "#########################" << RESET << endl;

	eigenvalues.push_back(slae[0][0]);
	reverse(eigenvalues.begin(), eigenvalues.end());

	return eigenvalues;
}

