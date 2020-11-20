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
	reverse_iteration_method(slae, eigenvalues_1);
	
	/* нахождение собственных значений и собственных векторов с помощью отношения Рэлея */
	Rayleigh_relation(slae);

	return 0;
}
