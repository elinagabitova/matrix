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

	Matrix matrix1 = Matrix (2, 2);	

	REQUIRE(matrix + matrix == matrix1);

}



SCENARIO("operator *") 

{

	Matrix matrix (2,2);

	Matrix matrix3  = Matrix (2,2);

	REQUIRE(matrix * matrix == matrix3);

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

	Matrix matrix2 = Matrix (2,2);

	REQUIRE(matrix == matrix2);

}

