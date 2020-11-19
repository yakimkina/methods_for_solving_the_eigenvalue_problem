#ifndef QR_METHOD_H
#define QR_METHOD_H

#include "../main.h"

vector<vector<VALUE_TYPE>>	create_T(int size);

void	build_R(vector<vector<VALUE_TYPE>> &slae, vector<vector<VALUE_TYPE>> &matT, int size);

#endif
