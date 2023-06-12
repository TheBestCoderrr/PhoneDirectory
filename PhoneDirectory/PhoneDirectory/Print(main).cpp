#include <iostream>
#include <string.h>

#include "Menu.h"

#define NAMESIZE 30
#define PHONESIZE 11

using namespace std;

int main() {
	int Size = 0;
	int* DynamicSize = &Size;
	char** PhoneDirectory = NULL;
	char name[NAMESIZE], PhoneNumber[PHONESIZE];

	Menu(PhoneDirectory, name, PhoneNumber, DynamicSize);

	delete[] PhoneDirectory;
}