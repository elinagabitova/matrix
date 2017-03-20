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



	Matrix();


	Matrix(int a, int b);


	void print(void) const;


	void input(char *path);

	void set(int x, int y, int z);

	int get(int x, int y) const;

	Matrix operator+ (Matrix a) const;

	Matrix operator* (Matrix a) const;


	Matrix& operator= (Matrix &other);


	bool operator== (Matrix &a) const;

	friend istream& operator>> (istream& infile, const Matrix& result);


	friend ostream& operator<< (ostream& os, const Matrix& a);


	~Matrix();

};
