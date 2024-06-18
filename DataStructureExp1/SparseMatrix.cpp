//SparseMatrix.cpp
#include "SparseMatrix.h"
#include<iostream>
#include<iomanip>
using namespace std;

SparseMatrix::SparseMatrix(int r, int c, int t) {
	rows = r, cols = c, terms = t;
	smArray = new MatrixTerm[terms];
	if (smArray == NULL) {
		cerr << "存储分配失败." << endl;
		exit(1);
	}
}

SparseMatrix SparseMatrix::FastTranspose() {
	SparseMatrix b(cols, rows, terms);
	if (terms > 0) {
		int* rowSize = new int[cols];
		int* rowStart = new int[cols];
		fill(rowSize, rowSize + cols, 0);

		for (int i = 0; i < terms; ++i)
			++rowSize[smArray[i].col];

		rowStart[0] = 0;
		for (int i = 1; i < cols; ++i)
			rowStart[i] = rowStart[i - 1] + rowSize[i - 1];

		for (int i = 0; i < terms; ++i) {
			int j = rowStart[smArray[i].col];
			b.smArray[j].row = smArray[i].col;
			b.smArray[j].col = smArray[i].row;
			b.smArray[j].value = smArray[i].value;
			++rowStart[smArray[i].col];
		}
		delete[] rowSize;
		delete[] rowStart;
	}
	return b;
}

void SparseMatrix::print() {
	cout << setw(8) << "row" << setw(8) << "col" << setw(8) << "value" << endl;
	for(int i=0;i<terms;++i)
		cout << setw(8) << smArray[i].row << setw(8) << smArray[i].col << setw(8) << smArray[i].value << endl;
}

SparseMatrix SparseMatrix::FastTransposeUpdated() {
	SparseMatrix b(cols, rows, terms);
	if (terms > 0) {
		int* rowS = new int[cols * 2];//0<=i<cols为size信息，cols<=i<2*cols为start信息
		
		fill(rowS, rowS + cols * 2, 0);
		for (int i = 0; i < terms; ++i)
			++rowS[smArray[i].col];

		rowS[cols] = 0;
		for (int i = cols + 1; i < 2 * cols; ++i)
			rowS[i] = rowS[i - 1] + rowS[i - 1 - cols];

		for (int i = 0; i < terms; ++i) {
			int j = rowS[cols + smArray[i].col];
			b.smArray[j].row = smArray[i].col;
			b.smArray[j].col = smArray[i].row;
			b.smArray[j].value = smArray[i].value;
			++rowS[cols + smArray[i].col];
		}
		delete[] rowS;
	}
	return b;
}