#ifndef MATRIX__H
#define MATRIX__H
#include "main.h"

static std::string format_spec = "";

namespace Laba {

	class Matrix {
	public:
		explicit Matrix(double value);
		Matrix(int n, int m);
		Matrix(int n, int m, double* data);
		Matrix(const Matrix& other);
		~Matrix();
		double& operator [](int n);
		double& operator ()(int i, int j);
		void PrintM();
		double* numbers;
		int rows, cols;
		void SetFormat(std::string format);
		Matrix& operator=(const Matrix& other);
		Matrix operator+(const Matrix& b);
		Matrix operator-(const Matrix& b);
		Matrix operator*(const Matrix& b);
		Matrix operator*(const double& a);
		Matrix operator - () const;
		Matrix operator += (const double& a);
		Matrix operator -= (const double& a);
		bool operator == (const Matrix& a) const;
		Matrix operator ||(Matrix a);
		double FindMax();
	};
	Matrix operator*(double b, const Matrix& c);
	std::ostream& operator << (std::ostream &os, const Matrix& c);
	;
}





#endif
