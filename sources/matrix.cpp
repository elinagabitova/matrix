#include "matrix.hpp"

int Matrix::Strings_() const
{
	return Strings;
}
int Matrix::Columns_() const
{
	return Columns;
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

Matrix::Matrix(const Matrix& result)
{
	Columns = result.Columns;
	Strings = result.Strings;
	matrix = new int*[Strings];
	
	for (int i = 0; i < Strings; ++i)
	{
		matrix[i] = new int[Columns];
		
		for (int j = 0; j < Columns; ++j)
		{
			matrix[i][j] = result.matrix[i][j];
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

istream& operator >> (istream& infile, const Matrix& result)
{
	for (int i = 0; i < result.Strings; i++)
	for (int j = 0; j < result.Columns; j++)
		infile >> result.matrix[i][j];
	
	return infile;
}

void Matrix::search(string filename) 
{
	ifstream infile;
	infile.open(filename);
	if (!infile.is_open())
		cout << "Error! Try again!" << endl;
	else
	{
		matrix = new int*[Strings];
		for (int i = 0; i < Strings; i++)
		{
			matrix[i] = new int[Columns];
			for (int j = 0; j < Columns; j++)
			{
				infile >> matrix[i][j];
			}
		}
	}
	infile.close();
}

ostream& operator << (ostream& outfile, const Matrix& result)
{
	for (int i = 0; i < result.Strings; i++)
	{
		for (int j = 0; j < result.Columns; j++)
		{
			outfile << result.matrix[i][j] << " ";
		}
	}
	outfile << endl;
	return outfile;
}

bool Matrix::operator == (const Matrix& a) const
{
	bool k = false;
	for (int i = 0; i < Strings; i++)
	{
		for (int j = 0; j < Columns; j++)
		{
			if (matrix[i][j] == a.matrix[i][j])
				k = true;
		}
	}
	return k;
}

Matrix Matrix::operator + (const Matrix& a) const
{
	if ((Columns != a.Columns) || (Strings != a.Strings)) {
		cout << "Error!";
	}
	else {
		Matrix result(Columns, Strings);
		for (int i = 0; i < Strings; ++i)
		{
			for (int j = 0; j < Columns; ++j)
			{
				result.matrix[i][j] = matrix[i][j] + a.matrix[i][j];
			}
		}
		return result;
	}
}

Matrix Matrix::operator * (const Matrix& a) const
{
	if (a.Strings != Columns){
		cout << "Error!";
	}
	else {
		Matrix result(Strings, a.Columns);
		
		for (int i = 0; i < Strings; i++)
		{
			for (int j = 0; j < m2.Columns; j++)
			{
				for (int k = 0; k < Columns; k++)
				{
					result.matrix[i][j] += matrix[i][k] * a.matrix[k][j];
				}
			}
		}
		return result;
	}
}

Matrix& Matrix::operator = (const Matrix& res)
{
	if (&res != this){
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
		

}
