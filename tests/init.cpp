#include <matrix.hpp>
#include <catch.hpp>

SCENARIO("par constructor") 

{

	Matrix matrix = Matrix(2,2);

	REQUIRE(matrix.strings_() == 2);

	REQUIRE(matrix.columns_() == 2);

}



SCENARIO("copy constructor") 

{

	Matrix matrix = Matrix(2,2);	

	Matrix copy(matrix);	

	REQUIRE(copy.strings_() == 2);

	REQUIRE(copy.columns_() == 2);

}


SCENARIO("operator +") 

{
	Matrix matrix = Matrix(2,2);
	Matrix matrix1 = Matrix(2,2);

	std::ifstream("text.txt") >> matrix1;

	REQUIRE(matrix1 + matrix == matrix + matrix );

}



SCENARIO("operator *") 

{

	Matrix matrix1 = Matrix(2,2);

	Matrix matrix3 = Matrix(2,2);

	REQUIRE(matrix1 * matrix1 == matrix3);

}

SCENARIO("operator =") 

{

	Matrix matrix1 = Matrix(2,2);

	Matrix matrix2 = matrix1;

	REQUIRE(matrix1 == matrix2);

}

SCENARIO("operator ==")
{

	Matrix matrix1 = Matrix(2,2);

	Matrix matrix2 = Matrix(2,2);

	REQUIRE(matrix1 == matrix2);

}

