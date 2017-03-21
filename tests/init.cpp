#include <matrix.hpp>
#include <catch.hpp>


SCENARIO("copy constructor") 

{

	Matrix matrix;	

	Matrix copy(matrix);	

	REQUIRE(copy.strings() == 2);

	REQUIRE(copy.columns() == 2);

}


SCENARIO("operator +") 

{
	Matrix matrix (2, 2);

	Matrix matrix2 (2, 2);	
	
	Matrix matrix3 (2, 2);	
	std::ifstream("matrix.txt") >> matrix 1;
	std::ifstream("matrix2.txt") >> matrix 2;
	std::ifstream("sum.txt") >> matrix 3;
	
	REQUIRE(matrix1 + matrix2 == matrix3);

}



SCENARIO("operator *") 

{

	Matrix matrix (2,2);
	Matrix matrix2 (2,2);
	Matrix matrix3 (2,2);
	std::ifstream("matrix.txt") >> matrix 1;
	std::ifstream("matrix2.txt") >> matrix 2;
	std::ifstream("multi.txt") >> matrix 3;

	REQUIRE(matrix1 * matrix2 == matrix3);

}

SCENARIO("operator =") 

{

	Matrix matrix (2,2);

	Matrix matrix2 = matrix;

	REQUIRE(matrix == matrix2);

}

SCENARIO("operator ==")
{

	Matrix matrix (2,2);

	Matrix matrix2 (2,2);

	REQUIRE(matrix == matrix2);

}

