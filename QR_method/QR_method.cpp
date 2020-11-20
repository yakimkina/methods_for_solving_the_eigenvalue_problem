#include "QR_method.h"

vector<VALUE_TYPE>	get_solution(vector<vector<VALUE_TYPE>> &slae, int size, vector<VALUE_TYPE> &b)
{
	vector<VALUE_TYPE> x;

	for (int i = 0; i < size; i++)
		x.push_back(b[i] / slae[i][i]);

	return x;
}

QR		QR_method(vector<vector<VALUE_TYPE>> &slae, int size)
{
	QR	solution;

	if (size == 1)
	{
		cout << RED << "[ERROR] Матрица размером 1х1!" << RESET << endl;
		return solution;
	}

	if (PRINT_STEPS)
		cout << endl << GREEN << "[МЕТОД QR]" << RESET << endl;

	vector<vector<VALUE_TYPE>> matR = slae;
	vector<vector<VALUE_TYPE>> matT = create_T(size);
	build_R(matR, matT, size);

	/* check if matrix is degenerate */
	/*if (is_degenerate(matR, size))
	{
		cout << RED << "[ERROR] Матрица вырождена!" << RESET << endl;
		print_slae(slae, size);
		return solution;
	}*/

	solution.R = matR;

	if (PRINT_STEPS)
	{
		cout << endl << MAGENTA << "[МЕТОД QR] Матрица R:" << RESET << endl;
		print_slae(matR, matR.size());
	}

	vector<vector<VALUE_TYPE>>	matQ = transpose(matT);
	solution.Q = matQ;

	if (PRINT_STEPS)
	{
		cout << endl << MAGENTA << "[МЕТОД QR] Матрица Q:" << RESET << endl;
		print_slae(matQ, matQ.size());
	}

	if (PRINT_CHECK)
	{
		/* check if QR == A */

//		make in class: if (A == multiplication(matQ, matR))

		cout << endl << YELLOW << "[проверка] A - QR:" << endl << "A:" << RESET << endl;
		vector<vector<VALUE_TYPE>>	matA = multiply(matQ, matR);
		vector<vector<VALUE_TYPE>>	delta = subtract_matrices(slae, matA, size, size);
		print_slae(delta, delta.size());
	}

//	reverse_traverse(matR, size);

//	vector<VALUE_TYPE>	x = get_solution(matR, size);
//	solution.x = &x;


	return solution;
}

