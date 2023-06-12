#include <iostream>
#include <string.h>

#include "CheckUserInfo.h"
#include "PrintPhoneDirectory.h"
#include "AddPhoneNumber.h"
#include "DeletePhoneNumber.h"

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

int main() {
	int a = 0;
	int* SIZE = &a;
	char** PhoneDirectory = NULL;
	char name[NAMESIZE], PhoneNumber[PHONESIZE];

	SetName(name);
	SetPhoneNumber(PhoneNumber);
	PhoneDirectory = AddPhoneNumber(PhoneDirectory, name, PhoneNumber, SIZE);

	//SetName(name);
	SetPhoneNumber(PhoneNumber);
	PhoneDirectory = DeletePhoneNumber(PhoneDirectory, PhoneNumber, SIZE);



	PrintPhoneDirectory(PhoneDirectory, *SIZE);
	delete[] PhoneDirectory;
}