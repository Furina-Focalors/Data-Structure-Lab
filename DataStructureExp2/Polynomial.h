//Polynomial.h
#pragma once

class Polynomial
{
public:
	Polynomial() {};
	Polynomial(int d);
	float F1a(float f);//公式1迭代
	float F1b(float f,int n);//公式1递归
	float F2a(float f);//公式2迭代
	float F2b(float f,int n);//公式2递归
	void print()const;

	int degree;
	float* coef;
};

