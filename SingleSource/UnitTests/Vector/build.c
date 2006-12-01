#include "helpers.h"

int main(int argc, char **Argv) {
	float X = 1.234;
	if (argc == 1123) X = 2.38213;
	FV A;
        A.V = (v4sf){ X, X, X, X };  // splat
        //A.V = A.V * A.V;
        printf("%f", A.A[1]);
	return 0;
}

