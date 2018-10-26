#include <iostream>

using namespace std;

void func(int *A) // Argument : 1-D array of integers
{

}

void func1(int B[][3]) // or (*B)[3] | Argument : 2-D arrray of integers
{

}

void func2(int C[][2][2]) // or (*C)[2][2] |  Arugment of 3-D array of integers
{

}


int main() {

	int C[3][2][2] = { {{2,5},{7,9}},
					  {{3,4},{6,1}},
					  {{0,8},{11,13}} };
	printf("%d %d %d %d\n", C, *C, C[0], &C[0][0]);
	printf("%d\n", *(C[0][0] + 1));

	int A[2] = { 1, 2 };
	int B[2][3] = { {2,4,6},{5,7,8} }; //B return int (*)[3]
	func(A); // A returns int*
	func1(B); // B returns int (*)[3]
	func2(C); // C returns int (*)[2][[2]

	return 0; 
}