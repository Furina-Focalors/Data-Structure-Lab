//Polynomial.cpp
#include "Polynomial.h"
#include<cmath>
#include<iostream>
#include<iomanip>
using namespace std;

Polynomial::Polynomial(int d) {
	degree = d;
	coef = new float[degree + 1];
}

void Polynomial::print()const {
	cout << coef[0];
	for (int i = 1; i <= degree; ++i) {
		cout << showpos << coef[i] << "x^" << noshowpos << i;
	}
}

float Polynomial::F1a(float f) {
	float result = 0;
	for (int i = 0; i <= degree; ++i) {
		result += coef[i] * pow(f, i);
	}
	return result;
}

float Polynomial::F1b(float f,int n) {
	if (n > degree)
		n = degree;
	if (n == 0)
		return coef[0];
	else
		return coef[n] * pow(f, n) + F1b(f, n - 1);
}

float Polynomial::F2a(float f) {
	float result = coef[degree];
	for (int i = degree - 1; i >= 0; --i) {
		(result *= f) += coef[i];
	}
	return result;
}

float Polynomial::F2b(float f,int n) {
	if (n == 0)
		return coef[degree];
	else
		return coef[degree-n] + f * F2b(f, n-1);
}
