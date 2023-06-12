#include <string.h>

bool CheckName(char** PhoneDirectory, char name[], const int SIZE) {
	unsigned short int CountCorrectLetters = 0, CountLetters = 0;

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; PhoneDirectory[i][j] != ' '; j++) {
			if (PhoneDirectory[i][j] == name[j])
				CountCorrectLetters++;
			CountLetters++;
		}
		if (CountCorrectLetters == strlen(name) && strlen(name) == CountLetters)
			return true;
		CountLetters = 0;
	}
	return false;
}

bool CheckRepeatNumber(char** PhoneDirectory, char PhoneNumber[], const int SIZE) { 
	unsigned short int CountCorrectNumbers = 0, index = 0, CountNumbers = 0;

	for (int i = 0; i < SIZE; i++) {
		while (PhoneDirectory[i][index] != '-')
			index++;
		index += 2;

		for (int j = 0; PhoneDirectory[i][index] != '\0'; j++) {
			if (PhoneDirectory[i][index++] == PhoneNumber[j])
				CountCorrectNumbers++;
			CountNumbers++;
		}
		if (CountCorrectNumbers == strlen(PhoneNumber) && strlen(PhoneNumber) == CountNumbers)
			return true;
		index = 0;
		CountNumbers = 0;
	}
	return false;
}

unsigned short int CountDublicateNames(char** PhoneDirectory, char name[], const int SIZE) {
	unsigned short int CountCorrectLetters = 0, CountDublicateNames = 0, CountLetters = 0;

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; PhoneDirectory[i][j] != ' '; j++) {
			if (PhoneDirectory[i][j] == name[j])
				CountCorrectLetters++;
			CountLetters++;
		}
		if (CountCorrectLetters == strlen(name) && strlen(name) == CountLetters)
			CountDublicateNames++;
		CountCorrectLetters = 0;
		CountLetters = 0;
	}
	return CountDublicateNames;
}
