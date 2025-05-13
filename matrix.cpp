#include "������1.h"
#include "matrix.h"
using namespace std;


namespace Laba {
	int rows, cols;
	double* numbers;
	
	//����������� � ���� ���������
	Matrix::Matrix(double value) {
		cols = 1;
		rows = 1;
		numbers = new double[1] { value };
	}

	//����������� � ������
	Matrix::Matrix(int n, int m) {
		cols = m;
		rows = n;
		numbers = new double[cols * rows] {0};
	}

	//����������� ���������� � ���� ������
	Matrix::Matrix(int n, int m, double* data) {
		cols = m;
		rows = n;
		numbers = new double[cols * rows] {0};
		for (int i = 0; i < cols * rows; i++) {
			numbers[i] = data[i];
		}
	}

	//����������� ����������
	Matrix::Matrix(const Matrix& other) {
		this->cols = other.cols;
		this->rows = other.rows;
		this->numbers = new double[cols * rows];

		for (int i = 0; i < cols * rows; i++) {
			this->numbers[i] = other.numbers[i];
		}
	}

	//����������
	Matrix::~Matrix() {
		delete[] numbers;
	}

	//��������� []
	double& Matrix::operator [](int n) {
		if (n <= cols * rows && n >= 0) {
			return numbers[n];
		}
		else {
			exit(1);
		}
	}

	//�������� ()
	double& Matrix::operator ()(int i, int j) {
		if (i < rows && i >= 0) {
			if (j < cols && j >= 0) {
				return numbers[i * rows + j];
			}
			else {
				exit(1);
			}
		}
		else{
			exit(1);
		}
	}
	
	//������� ������
	void Matrix::PrintM()
	{
		if (format_spec.empty()) {
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < cols; j++) {
					cout << numbers[i * cols + j] << "\t";
				}
				cout << "\n";
			}
		}
		else {
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < cols; j++) {
					cout << std::vformat(format_spec, make_format_args(numbers[i * cols + j])) << "\t";
				}
				cout << endl;
			}
		}
	}

	//������� ��� ��������� �������
	void Matrix::SetFormat(string format)
	{
		format_spec = format;
	}

	//�������� =
	Matrix& Matrix::operator=(const Matrix& other)
	{
		if (this == &other) {
			return *this;  // ����������������
		}


		cols = other.cols;
		rows = other.rows;
		numbers = new double[cols * rows];

		for (int i = 0; i < cols * rows; i++) {
			numbers[i] = other.numbers[i];
		}

		return *this;
	}
	
	//�������� +
	Matrix Matrix::operator+(const Matrix& b) {
		Matrix c(rows, cols);
		if (cols != b.cols || rows != b.rows) { cout << "����������� �������"; exit(1); }
		else {
			for (int i = 0; i < cols * rows; i++) {
				c[i] = numbers[i] + b.numbers[i];
			}
		}
		return c;
	}

	//������� * �� ������
	Matrix Matrix::operator* (const Matrix& b)
	{
		Matrix c(rows, b.cols);
		if (cols != b.rows) { cout << "�� ���������� �������"; exit(1); }
		
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < b.cols; j++) {
				for (int k = 0; k < cols; k++) {
					c[i * b.cols + j] += numbers[i * cols + k] * b.numbers[k * b.cols + j];
				}
			}
		}
		return c;
	}

	//�������� -
	Matrix Matrix::operator-(const Matrix& b) {
		Matrix c(rows, cols);
		if (cols != b.cols || rows != b.rows) {
			cout << "����������� �������";
		}
		for (int i = 0; i < cols * rows; i++) {
			c[i] = numbers[i] - b.numbers[i];
		}
		return c;
	}

	//�������� <<
	std::ostream& operator<<(std::ostream& os, const Matrix& c)
	{
		if (format_spec.empty()) {
			for (int i = 0; i < c.rows; i++) {
				for (int j = 0; j < c.cols; j++) {
					os << c.numbers[i * c.cols + j] << "\t";
				}
				os << "\n";
			}
		}
		else {
			for (int i = 0; i < c.rows; i++) {
				for (int j = 0; j < c.cols; j++) {
					os << std::vformat(format_spec, make_format_args(c.numbers[i * c.cols + j])) << "\t";
				}
				os << endl;
			}
		}
		return os;
	}
	
	//��������: ����� �������� �� �������
	Matrix operator*(double a, const Laba::Matrix & b)
	{
		Laba::Matrix c(b);
		for (int i = 0; i < c.rows * c.cols; i++) {
			c.numbers[i] = c.numbers[i] * a;
		}
		return c;
	}
	
	//��������: ������� �������� �� �����
	Matrix Matrix::operator*(const double& a) {
		Matrix c(rows, cols);
		for (int i = 0; i < rows*cols; i++) {
			c.numbers[i] = numbers[i] * a;
		}
		return c;
	}
	
	// ������� �����
	Matrix Matrix::operator - () const {
		for (int i = 0; i < this->cols * this->rows; i++) {
			this->numbers[i] = -this->numbers[i];
		}
		return *this;
	}

	// �������� +=
	Matrix Matrix::operator+= (const double& a) {
		for (int i = 0; i < this->cols * this->rows; i++) {
			this->numbers[i] += a;
		}
		return *this;
	}

	// �������������� ������� 1
	Matrix Matrix::operator||(Matrix a)
	{
		Matrix c(a.cols, this->cols);
		if (a.rows != 1) { cout << "�� ��������� ����"; exit(1); }
		else {
			for (int i = 0; i < a.cols; i++) {
				int kakuyu_stroku_bratb = a.numbers[i];
				for (int j = 0; j < this->cols; j++) {
					c.numbers[i * c.cols + j] = this->numbers[kakuyu_stroku_bratb * cols + j];
				}
			}
		}
		return c;
	}

	// ���������� ������������� ��������
	double Matrix::FindMax()
	{
		double max = -9999999999999999999;
		for (int i = 0; i < this->cols * this->rows; i++) {
			if (this->numbers[i] >= max) {
				max = this->numbers[i];
			}
		}
		return max;
	}

	// �������� -=
	Matrix Matrix::operator-= (const double& a) {
		for (int i = 0; i < this->cols * this->rows; i++) {
			this->numbers[i] -= a;
		}
		return *this;
	}
	
	// �������� ==
	bool Matrix::operator==(const Matrix& a) const 
	{
		bool flg = true;
		for (int i = 0; i < this->cols * this->rows; i++) {
			if (this->numbers[i] != a.numbers[i]) {
				flg = false;
			}
		}
		return flg;
	}

}

