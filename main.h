#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

#define FILE_NAME	"../TEST/D0.TXT"
#define WIDTH	8
#define PREC	4
//#define PREC_ZERO	0.000001
#define EPSILON	0.0001

#define PRINT_STEPS	false
#define PRINT_CHECK	false

/* colorful output */
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */

/* multiplication */
#define A__ID_COLUMN	0
#define A__B_COLUMN		0
#define B__ID_COLUMN	1
#define B__B_COLUMN		1

using namespace std;

typedef double VALUE_TYPE;

struct	QR
{
	vector<vector<VALUE_TYPE>>	Q;
	vector<vector<VALUE_TYPE>>	R;
//	vector<VALUE_TYPE>			*x = NULL;
};

void	print_vector(vector<VALUE_TYPE> x);
void 	print_slae(vector<vector<VALUE_TYPE>> slae, int m, int n); /* print SLAE with b vector */
void	print_slae(vector<vector<VALUE_TYPE>> &slae, int size); /* print SLAE without b vector */

vector<vector<VALUE_TYPE>> 	parsing_file();

vector<vector<VALUE_TYPE>>	transpose(vector<vector<VALUE_TYPE>> &slae);
vector<vector<VALUE_TYPE>>	multiply(vector<vector<VALUE_TYPE>> &a, vector<vector<VALUE_TYPE>> &b);
vector<vector<VALUE_TYPE>>	multiply(vector<vector<VALUE_TYPE>> &a, vector<vector<VALUE_TYPE>> &b, int size, VALUE_TYPE value);
vector<vector<VALUE_TYPE>>	subtract_matrices(vector<vector<VALUE_TYPE>> a, vector<vector<VALUE_TYPE>> b, int m, int n);
bool	is_degenerate(vector<vector<VALUE_TYPE>> &slae, int size);
void	reverse_traverse(vector<vector<VALUE_TYPE>> &slae, int size);

QR		QR_method(vector<vector<VALUE_TYPE>> &slae, int size);


vector<VALUE_TYPE>		find_eigenvalues(vector<vector<VALUE_TYPE>> slae);
vector<VALUE_TYPE>		find_eigenvalues_with_shift(vector<vector<VALUE_TYPE>> slae);
vector<vector<VALUE_TYPE>> 	to_Hessenberg_shape(vector<vector<VALUE_TYPE>> H);

#endif
