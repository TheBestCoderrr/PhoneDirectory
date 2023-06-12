#include <iostream>
#include <string.h>

using namespace std;

void PrintPhoneDirectory(char** PhoneDirectory, const int SIZE) {
	cout << "Contacts:" << endl;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < strlen(PhoneDirectory[i]); j++)
			cout << PhoneDirectory[i][j];
		cout << endl;
	}
	cout << endl;
}