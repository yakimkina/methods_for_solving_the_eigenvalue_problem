#include "main.h"

void 	reverse_iteration_method(vector<vector<VALUE_TYPE>> slae, vector<VALUE_TYPE> &eigenvalues)
{
	int size = slae.size();

	cout << endl << MAGENTA << "[МЕТОД ОБРАТНЫХ ИТЕРАЦИЙ]" << endl;
	for (int i = 0; i < eigenvalues.size(); i++)
	{
		shift_slae(slae, size, eigenvalues[i]);

		vector<VALUE_TYPE> x;
		vector<VALUE_TYPE> y = {1, 1, 1, 1};
		do
		{
			x = normalization(y, size);

			QR	solution = QR_method(slae, size);
			reverse_traverse(solution.R, size, x);
			y = get_solution(solution.R, size, x);

		} while (abs(scalar_multiplication(x, y) /
					 (vector_norm(x, size) * vector_norm(y, size))) > (1 + EPSILON));

		vector<VALUE_TYPE>	solution = normalization(y, size);
		cout << GREEN << "собств. значение = " << eigenvalues[i] << ", собств. вектор: ";
		print_vector(solution);
		cout << RESET;

		vector<VALUE_TYPE>	check = multiply(slae, solution, size);
		cout << MAGENTA << "проверка: ";
		print_vector(check);
		cout << RESET;

		unshift_slae(slae, size, eigenvalues[i]);
	}
}

