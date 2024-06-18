//SparseMatrix.h
#pragma once
class MatrixTerm {
	friend class SparseMatrix;
public:
//private:
	int row, col, value;
};

class SparseMatrix
{
public:
	SparseMatrix(int r, int c, int t);

	SparseMatrix FastTranspose();

	SparseMatrix FastTransposeUpdated();

	SparseMatrix Add(SparseMatrix b);

	SparseMatrix Multiply(SparseMatrix b);
	
	void print();
//private:
	int rows, cols, terms, capacity;
	MatrixTerm* smArray;
};

