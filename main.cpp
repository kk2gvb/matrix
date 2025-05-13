#include "main.h"

using namespace std;
using namespace Laba;


int main()
{
	setlocale(LC_ALL, "RU");
	double* pa = new double[9] {1, 2, 3, 23, 4, 6, 4, 3, 4,};
	double* pb = new double[15] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 22, 33, 44, 55};
	double* pv = new double[6] {0, 2, 1};
	double* pp = new double[9] {1, 0, 0, 0, 0, 1, 0, 1, 0};
	Matrix A(3, 3, pa);
	Matrix B(3, 5, pb);
	Matrix C(5, 3, pb);
	Matrix P(3, 3, pp);
	Matrix V(1, 3, pv);
	Matrix Y = V;
	cout << "Матрица А:\n" << A << "\n";
	cout << "Матрица B:\n" << B << "\n";
	cout << "Матрица C:\n" << C << "\n";
	cout << "Матрица P:\n" << P << "\n";
	cout << "Вектор V:\n" << V << "\n";
	
	/*cout << "A + B \n";
	cout << A + B << "\n";*/

	/*cout << "A - B \n";
	cout << A - B << "\n";*/

	
	/*cout << "A * C";
	cout << "А * C\n";
	cout << A * C << "\n";*/
	/*cout << "А * число\n";
	cout << A * 2;*/
	/*cout << "\n-(число * А)\n";
	cout << -(2*A);*/
	/*cout << "Проверка оператора += и -=(А += 4 and B -= 4)\n";
	Matrix D = A += 4;
	cout << D << "\n";
	Matrix E = B -= 4;
	cout << E << "\n";*/
	/*bool ans = (A == B);
	cout << ans;*/

	Matrix Ind2_1 = P*A;
	Matrix Ind2_2 = A || V;

	cout << "P * A:\n" << Ind2_1 << "\n";
	cout << "A || V:\n" << Ind2_2 << "\n";


	return 0;

}
