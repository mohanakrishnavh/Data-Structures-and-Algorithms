#include <iostream>
#include <string>

using namespace std;

void print(char *c) {
	int i = 0;
	while (c[i] != '\0') {
		printf("%c", c[i]);
		i++;
	}
	cout << endl;
}

void print2(char *c) {
	while (*c != '\0') {
		printf("%c", *c);
		c++;
	}
}

int main() {
	char C[4];
	C[0] = 'J';
	C[1] = 'O';
	C[2] = 'H';
	C[3] = 'N';
	printf("%s\n", C);

	char Ch[20];
	Ch[0] = 'J';
	Ch[1] = 'O';
	Ch[2] = 'H';
	Ch[3] = 'N';
	Ch[4] = '\0';
	printf("%s\n", Ch);
	cout << "Size : " << strlen(Ch) << endl;

	char Ch2[] = "John";
	printf("Size in bytes: %d\n", sizeof(Ch2));

	char Ch3[] = {'J', 'o','h', 'n', '\0'};
	printf("Size in bytes: %d\n", sizeof(Ch3));

	print(Ch);
	print2(Ch);

	//char C[20] = "Hello"; // string gets stored in the space for array
	//char *C = "Hello"; //string gets stored as compile time constant - we can't modify these
	return 0;
}