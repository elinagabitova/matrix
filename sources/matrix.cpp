#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

class Matrix
{
private:

	int columns;
	int strings;
	int **matrix;

public:

	Matrix()
	{

	};

	Matrix(int a, int b)
	{
		columns = b;
		strings = a;
		matrix = new int*[a];

		for (int i = 0; i < a; i++)
		{
			matrix[i] = new int[b]{0};
		}
	};

	void print(void) const
	{
		for (int i = 0; i < strings; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				cout << get(i, j) << " ";
			}
			cout << endl;
		}
		cout << endl;
	};

	void input(char *path)
	{
		ifstream file;
		file.open(path);


		for (int i = 0; i < strings; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				char *temp = new char[5]; // file <<  
				file.getline(temp, 5);
				set(i, j, atoi(temp));
			}
		}
	};

	void set(int x, int y, int z)
	{
		matrix[x][y] = z;
	};

	int get(int x, int y) const
	{
		return matrix[x][y];
	};

	Matrix operator+ (Matrix a) const
	{
		Matrix c(strings, columns);


		for (int i = 0; i < strings; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				c.set(i, j, a.get(i, j) + get(i, j));
			}
		}
		return c;
	};

	Matrix operator* (Matrix a) const
	{
		Matrix c(strings, a.columns);

		for (int i = 0; i < strings; i++)
		{
			for (int j = 0; j < a.columns; j++)
			{
				int temp = 0;
				for (int k = 0; k < strings; k++)
				{
					temp += get(i, k) * a.get(k, j);
				}
				c.set(i, j, temp);
			}
		}

		return c;
	};

	Matrix& operator= (Matrix &other) //const Matrix & other
	{
		if (this != &other)
		{
			for (int i = 0; i < strings; i++)
			{
				delete[] matrix[i];
			}

			delete[] matrix;

			columns = other.columns;
			strings = other.strings;

			matrix = new int*[strings];

			for (int i = 0; i < strings; i++)
			{
				matrix[i] = new int[columns]{0};
			}

			matrix = other.matrix;
		}
		return *this;
	};

	bool operator== (Matrix &a) const
	{
		bool k = false;

		for (int i = 0; i < strings; i++){

			for (int j = 0; j < columns; j++){

				if (matrix[i][j] == a.matrix[i][j])

					k = true;

			}

		}

		return k;
	}

	friend istream& operator>> (istream& infile, const Matrix& result)

	{

		for (int i = 0; i < result.strings; i++)

			for (int j = 0; j < result.columns; j++)

				infile >> result.matrix[i][j];

		return infile;

	}

	friend ostream& operator<< (ostream& os, const Matrix& a)
	{
		for (int i = 0; i < a.strings; i++)
		{
			for (int j = 0; j < a.columns; j++)
			{
				os << a.get(i, j) << " ";
			}
			os << endl;
		}
		os << endl;
		return os;
	}

	friend istream& operator>> (istream& is, Matrix& a)
	{
		
	}

	~Matrix()
	{
		/*for (int i = 0; i < strings; i++)
		{
			delete[] matrix[i];
		}

		delete[] matrix;*/
	};
};


