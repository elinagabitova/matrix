#include <matrix.hpp>
#include <catch.hpp>

SCENARIO("def constructor")
{
	Matrix matrix;
	REQUIRE(matrix.Strings_() == 0);
	REQUIRE(matrix.Columns_() == 0);
}

SCENARIO("param constructor") 
{
	Matrix matrix(2, 2);
	REQUIRE(matrix.Strings_() == 2);
	REQUIRE(matrix.Columns_() == 2);
}

SCENARIO("copy constructor") 
{
	Matrix matrix (2, 2);	
	Matrix copy(matrix);	
	REQUIRE(copy.Strings_() == 2);
	REQUIRE(copy.Columns_() == 2);
}


SCENARIO("operator +") 
{
	Matrix matrix1 (2, 2);
	Matrix matrix2 (2, 2);
	Matrix matrix3 (2, 2);	
	std::ifstream("matrix.txt") >> matrix1;
	std::ifstream("matrix1.txt") >> matrix2;
	std::ifstream("sum.txt") >> matrix3;
	REQUIRE(matrix1 + matrix2 == matrix3);
}

SCENARIO("operator *") 
{
	Matrix matrix1 (2, 2);
	Matrix matrix2 (2, 2);
	Matrix matrix3 (2, 2);	
	std::ifstream("matrix.txt") >> matrix1;
	std::ifstream("matrix1.txt") >> matrix2;
	std::ifstream("multi.txt") >> matrix3;
	REQUIRE(matrix1 * matrix2 == matrix3);
}
SCENARIO("operator =") 
{
	Matrix matrix(2, 2);
	Matrix matrix = matrix1;
	REQUIRE(matrix == matrix1);
}
SCENARIO("operator ==")
{
	Matrix matrix(2, 2);
	Matrix matrix1(2, 2);
	REQUIRE(matrix == matrix1);
}
