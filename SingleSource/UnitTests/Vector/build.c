#include "helpers.h"

int main(int argc, char **Argv) {
	float X = 1.234;
	if (argc == 1123) X = 2.38213;
	FV A;
        A.V = (v4sf){ X, X, X, X };  // splat
        A.V = A.V * A.V;
        printFV(&A);
        A.V = (v4sf){ X, X, 0, 0 };
	A.V = A.V+A.V;
        printFV(&A);
	return 0;
}

