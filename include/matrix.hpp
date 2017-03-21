#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Matrix
{
private:
	int Columns;
	int Strings;
	int **matrix;
public:
	Matrix();

	Matrix(int _Columns, int _Strings);

	Matrix(const Matrix& result);

	~Matrix();

	int Columns_();

	int Strings_();

	void search(string filename);

	bool operator == (const Matrix& m2) const;

	Matrix operator + (const Matrix& m2) const;

	Matrix operator * (const Matrix& m2) const;

	Matrix& operator = (const Matrix& result);

	friend ostream& operator << (ostream& outfile, const Matrix& result);

	friend istream& operator >> (istream& infile, const Matrix& result);
};
