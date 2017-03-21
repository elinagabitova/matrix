#include "matrix.hpp"

int Matrix::Columns_() const
{
	return Columns;
}

int Matrix::Strings_() const
{
	return Strings;
}

Matrix::Matrix()
{
	Columns = 0;
	Strings = 0;
	matrix = new int*[Strings];
	for (int i = 0; i < Strings; i++)
	{
		matrix[i] = new int[Columns];
	}
}

Matrix::Matrix(int _Columns, int _Strings)
{
	Columns = _Columns;
	Strings = _Strings;
	matrix = new int*[Strings];
	for (int i = 0; i < Strings; ++i)
	{
		matrix[i] = new int[Columns];
		for (int j = 0; j < Columns; ++j)
		{
			matrix[i][j] = 0;
		}
	}
}

Matrix::Matrix(const Matrix& res)
{
	Columns = res.Columns;
	Strings = res.Strings;
	matrix = new int*[Strings];
	
	for (int i = 0; i < Strings; ++i)
	{
		matrix[i] = new int[Columns];
		for (int j = 0; j < Columns; ++j)
		{
			matrix[i][j] = res.matrix[i][j];
		}
	}
}

Matrix::~Matrix()
{
	for (int i = 0; i < Strings; ++i)
	{
		delete[]matrix[i];
	}
	delete[]matrix;
}

istream& operator >> (istream& infile, const Matrix& res) const
{
	for (int i = 0; i < res.Strings; i++)
	for (int j = 0; j < res.Columns; j++)
		infile >> res.matrix[i][j];
	return infile;
}

void Matrix::search(string filen) const
{
	ifstream file;
	file.open(filen);
	if (!file.is_open())
		cout << "Error! Try again!" << endl;
	else
	{
		matrix = new int*[Strings];
		for (int i = 0; i < Strings; i++)
		{
			matrix[i] = new int[Columns];
			for (int j = 0; j < Columns; j++)
			{
				file >> matrix[i][j];
			}
		}
	}
	file.close();
}

ostream& operator << (ostream& outfile, const Matrix& resu)
{
	for (int i = 0; i < res.Strings; i++)
	{
		for (int j = 0; j < resu.Columns; j++)
		{
			outfile << res.matrix[i][j] << " ";
		}
	}
	outfile << endl;
	return outfile;
}

bool Matrix::operator == (const Matrix& m2) const
{
	bool k = false;
	for (int i = 0; i < Strings; i++)
	{
		for (int j = 0; j < Columns; j++)
		{
			if (matrix[i][j] == m2.matrix[i][j])
				k = true;
		}
	}
	return k;
}

Matrix Matrix::operator + (const Matrix& m2) const
{
	if ((Columns != m2.Columns) || (Strings != m2.Strings)) 
	{
		cout << "Error!";
	}
	else 
	{
		Matrix result(Columns, Strings);
		for (int i = 0; i < Strings; ++i)
		{
			for (int j = 0; j < Columns; ++j)
			{
				result.matrix[i][j] = matrix[i][j] + m2.matrix[i][j];
			}
		}
		return result;
	}
}

Matrix Matrix::operator * (const Matrix& m2) const
{
	if (m2.Strings != Columns)
	{
		cout << "Error!";
	}
	else 
	{
		Matrix res(Strings, m2.Columns);
		
		for (int i = 0; i < Strings; i++)
		{
			for (int j = 0; j < m2.Columns; j++)
			{
				for (int k = 0; k < Columns; k++)
				{
					res.matrix[i][j] += matrix[i][k] * m2.matrix[k][j];
				}
			}
		}
		return result;
	}
}

Matrix& Matrix::operator = (const Matrix& res)
{
	if (&result != this)
	{
		for (int i = 0; i < Strings; i++)
		{
			delete[] matrix[i];
		}
		delete[] matrix;
	}
	Strings = res.Strings;
	Columns = res.Columns;
	
	matrix = new int*[Strings];
	
	for (int i = 0; i < Strings; i++)
	{
		matrix[i] = new int[Columns];
		for (int j = 0; j < Columns; j++)
		{
			matrix[i][j] = res.matrix[i][j];
		}
	}
	return *this;


