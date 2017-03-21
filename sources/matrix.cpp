#include <matrix.hpp>

	Matrix :: Matrix(){};

	Matrix :: Matrix(int a, int b)
	{
		columns = b;
		strings = a;
		matrix = new int*[a];

		for (int i = 0; i < a; i++)
		{
			matrix[i] = new int[b]{0};
		}
	};

	 void Matrix :: print(void) 
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

	void Matrix :: input(string filen)
	{
		ifstream file;
		file.open(filen);
		

		matrix[i] = new *int [strings];
		for (int i = 0; i < strings; i++)
		{
			matrix[i] = new *int [columns];
			for (int j = 0; j < columns; j++)
			{
				file >> matrix[i][j];
			}
		}
	};

	void Matrix :: set(int x, int y, int z)
	{
		matrix[x][y] = z;
	};

	int Matrix :: get(int x, int y) const
	{
		return matrix[x][y];
	};

	Matrix Matrix:: operator+ (Matrix a) const
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

	Matrix Matrix :: operator* (Matrix a) const
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

	Matrix& Matrix :: operator= (Matrix &other) 
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

	bool Matrix :: operator== (Matrix &a) const
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

	istream& operator>> (istream& infile, const Matrix& result)

	{

		for (int i = 0; i < result.strings; i++)

			for (int j = 0; j < result.columns; j++)

				file >> result.matrix[i][j];

		return file;

	}

	 ostream& operator<< (ostream& os, const Matrix& a)
	{
		for (int i = 0; i < a.strings; i++)
		{
			for (int j = 0; j < a.columns; j++)
			{
				os << a.matrix[i, j] << " ";
			}
			os << endl;
		}
		os << endl;
		return os;
	}


	Matrix :: ~Matrix()
	{
		/*for (int i = 0; i < strings; i++)
		{
			delete[] matrix[i];
		}

		delete[] matrix;*/
	};
};


