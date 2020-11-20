#include "main.h"

static vector<VALUE_TYPE>	get_y(int i)
{
	switch (i)
	{
		case 0:
			return {-0.8, 0, -0.2, -0.4};
		case 1:
			return {0, 0.7, -0.5, 0.3};
		case 2:
			return {0.4, 0, -0.43, -0.75};
		default:
			return {0, 0.6, 0.6, -0.3};
	}
}

void 	Rayleigh_relation(vector<vector<VALUE_TYPE>> slae)
{
	int	size = slae.size();

	cout << endl << MAGENTA << "[ОТНОШЕНИЕ РЭЛЕЯ]" << endl;
	for (int i = 0; i < size; i++)
	{
		VALUE_TYPE	ro_x;
		vector<VALUE_TYPE> x;
		vector<VALUE_TYPE> y = get_y(i);
		
		do
		{
			x = normalization(y, size);

			vector<VALUE_TYPE>	Ax = multiply(slae, x, size);
			ro_x = scalar_multiplication(Ax, x);

			shift_slae(slae, size, ro_x);

			QR	solution = QR_method(slae, size);
			reverse_traverse(solution.R, size, x);
			y = get_solution(solution.R, size, x);

			unshift_slae(slae, size, ro_x);
		} while (abs(scalar_multiplication(x, y) /
					 (vector_norm(x, size) * vector_norm(y, size))) > (1 + EPSILON));

		vector<VALUE_TYPE>	solution = normalization(y, size);
		cout << GREEN << "собств. значение = " << ro_x << ", собств. вектор: ";
		print_vector(solution);
		cout << RESET;

		shift_slae(slae, size, ro_x);

		vector<VALUE_TYPE>	check = multiply(slae, solution, size);
		cout << MAGENTA << "проверка: ";
		print_vector(check);
		cout << RESET;

		unshift_slae(slae, size, ro_x);
	}
}

