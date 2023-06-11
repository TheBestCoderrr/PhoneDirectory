#include <iostream>
#include <string.h>

#include "AddPhoneNumber.h"

#define NAMESIZE 30
#define PHONESIZE 10

using namespace std;

void SetName(char name[]) {
	cout << "Enter Name: ";
	cin.getline(name, NAMESIZE);
}

void SetPhoneNumber(char PhoneNumber[]) {
	cout << "Enter Phone Number: ";
	cin.getline(PhoneNumber, PHONESIZE);
}

void PrintArr(char** PhoneDirectory, const int SIZE) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < strlen(PhoneDirectory[i]); j++)
			cout << PhoneDirectory[i][j];
		cout << endl;
	}
	cout << endl;
}

int main() {
	int a = 0;
	int* SIZE = &a;
	char** PhoneDirectory = NULL;
	char name[NAMESIZE], PhoneNumber[PHONESIZE];

	SetName(name);
	SetPhoneNumber(PhoneNumber);

	PhoneDirectory = AddPhoneNumber(PhoneDirectory, name, PhoneNumber, SIZE);
	PhoneDirectory = AddPhoneNumber(PhoneDirectory, name, PhoneNumber, SIZE);

	PrintArr(PhoneDirectory, *SIZE);
	delete[] PhoneDirectory;
}