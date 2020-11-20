#include "main.h"

int main()
{
	vector<vector<VALUE_TYPE>>	slae = parsing_file();
	int size = slae.size();

	cout << endl << MAGENTA << "СЛАУ:" << RESET << endl;
	print_slae(slae, slae.size());


	/* без Хессенберга, без сдвига */
	vector<VALUE_TYPE>	eigenvalues_1 = find_eigenvalues(slae);
	cout << GREEN << "собственные значения: ";
	print_vector(eigenvalues_1);
	cout << GREEN << "#########################" << RESET << endl;


	/* с Хессенбергом, без сдвига */
	vector<vector<VALUE_TYPE>>	matH = to_Hessenberg_shape(slae);
	cout << endl << MAGENTA << "Форма Хессенберга:" << RESET << endl;
	print_slae(matH, matH.size());

	vector<VALUE_TYPE>	eigenvalues_2 = find_eigenvalues(matH);
	cout << GREEN << "собственные значения: ";
	print_vector(eigenvalues_2);
	cout << GREEN << "#########################" << RESET << endl;


	/* без Хессенберга, со сдвигом */
	vector<VALUE_TYPE>	eigenvalues_3 = find_eigenvalues_with_shift(slae);
	cout << GREEN << "собственные значения: ";
	print_vector(eigenvalues_3);
	cout << GREEN << "#########################" << RESET << endl;


	/* с Хессенбергом, со сдвигом */
	vector<VALUE_TYPE>	eigenvalues_4 = find_eigenvalues_with_shift(matH);
	cout << GREEN << "собственные значения: ";
	print_vector(eigenvalues_4);
	cout << GREEN << "#########################" << RESET << endl;


	/* нахождение собственных векторов методом обратных итераций */
	cout << endl << MAGENTA << "[МЕТОД ОБРАТНЫХ ИТЕРАЦИЙ]" << endl;
	for (int i = 0; i < eigenvalues_1.size(); i++)
	{
		shift_slae(slae, size, eigenvalues_1[i]);

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

		unshift_slae(slae, size, eigenvalues_1[i]);

		cout << GREEN << "собств. значение = " << eigenvalues_1[i] << ", собств. вектор: ";
		print_vector(normalization(y, size));
		cout << RESET;
	}

	
	/* нахождение собственных значений и собственных векторов с помощью отношения Рэлея */
	cout << endl << MAGENTA << "[ОТНОШЕНИЕ РЭЛЕЯ]" << endl;
	for (int i = 0; i < size; i++)
	{
		VALUE_TYPE	ro_x;
		vector<VALUE_TYPE> x;
		vector<VALUE_TYPE> y = {0, 0, 0, 0};
		y[i] = 1;
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

		cout << GREEN << "собств. значение = " << ro_x << ", собств. вектор: ";
		print_vector(normalization(y, size));
		cout << RESET;
	}

	return 0;
}
