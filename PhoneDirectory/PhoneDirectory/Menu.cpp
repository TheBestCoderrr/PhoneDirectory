#include <iostream>
#include <string.h>

#include "CheckUserInfo.h"
#include "PrintPhoneDirectory.h"
#include "AddPhoneNumber.h"
#include "DeletePhoneNumber.h"
#include "SortPhoneDirectory.h"

#define NAMESIZE 30
#define PHONESIZE 11

using namespace std;

void SetName(char name[]) {
	cout << "Enter Name: ";
	cin.getline(name, NAMESIZE);
}

void SetPhoneNumber(char PhoneNumber[]) {
	cout << "Enter Phone Number: ";
	cin.getline(PhoneNumber, PHONESIZE);
}

unsigned short int FindNameIndex(char** PhoneDirectory, char Name[], const int SIZE) {
	unsigned short int CountCorrectLetters = 0;

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < strlen(Name); j++) {
			if (PhoneDirectory[i][j] == Name[j])
				CountCorrectLetters++;
		}
		if (CountCorrectLetters == strlen(Name))
			return i;
	}
	return NULL;
}

void InitPhoneNumber(char** PhoneDirectory, char name[],char PhoneNumber[], const int SIZE) {
	unsigned short int NameIndex;

	NameIndex = FindNameIndex(PhoneDirectory, name, SIZE);
	int index = 0, i = 0;
	while (PhoneDirectory[NameIndex][index] != '-')
		index++;
	index += 2;

	for (; PhoneDirectory[NameIndex][index] != '\0'; i++, index++)
		PhoneNumber[i] = PhoneDirectory[NameIndex][index];
	PhoneNumber[i] = '\0';
}

char ContinueOrCancelChoice() {
	char ControlQuestion;
	cout << "Are you Sure to continue?\nPlus(+) -  Continue\nMinus(-) - Cancel" << endl;
	while (true) {
		cout << "Choose variant:";
		cin >> ControlQuestion;
		if (ControlQuestion == '+' || ControlQuestion == '-')
			break;
	}
	return ControlQuestion;
}

void Menu(char** PhoneDirectory, char name[],char PhoneNumber[], int* SIZE) {
	cout << "Menu:\n0 - Exit;\n1 - Print Contacts;\n2 - Add Contact;\n3 - Delete Contact;\n4 - Sort Names;\n5 - Sort Phone Numbers; " << endl;
	short int UserMenuChoice;

	while (true) {
		cout << "Choose variant(Menu): ";
		cin >> UserMenuChoice;
		cout << endl;
		cin.getline(name, 1);

		if (UserMenuChoice == 0) {
			cout << "Exit!" << endl;
			break;
		}
		switch (UserMenuChoice) {
			case 1:
				PrintPhoneDirectory(PhoneDirectory, *SIZE);
				break;
			case 2:
				SetName(name);

				while (true) {
					SetPhoneNumber(PhoneNumber);
					if (CheckRepeatNumber(PhoneDirectory, PhoneNumber, *SIZE))
						cout << "This number is already in your contacts!" << endl;
					else
						break;
				}
				
				if (ContinueOrCancelChoice() == '+') {
					PhoneDirectory = AddPhoneNumber(PhoneDirectory, name, PhoneNumber, SIZE);
				}
				else
					cout << "Adding a new number has been cancelled!" << endl;
				
				break;

			case 3:
				while (true) {
					SetName(name);
					if (CheckName(PhoneDirectory, name, *SIZE) == false)
						cout << "Name Not Found!" << endl;
					else
						break;
				}
				
				if (CountDublicateNames(PhoneDirectory, name, *SIZE) >= 2) {
					cout << "There is more than one number with this name in contacts! Set Phone number to delete this contact" << endl;
					SetPhoneNumber(PhoneNumber);

					if (ContinueOrCancelChoice() == '+') {
						PhoneDirectory = DeletePhoneNumber(PhoneDirectory, PhoneNumber, SIZE);
					}
					else
						cout << "Delete Canceled!" << endl;
				}
				else {
					InitPhoneNumber(PhoneDirectory, name, PhoneNumber, *SIZE);

					if (ContinueOrCancelChoice() == '+') {
						PhoneDirectory = DeletePhoneNumber(PhoneDirectory, PhoneNumber, SIZE);
					}
					else
						cout << "Deletion Cancelled!" << endl;
				}
				break;

			case 4:
				if (ContinueOrCancelChoice() == '+') {
					SortByNames(PhoneDirectory, *SIZE);
				}
				else
					cout << "Sort cancelled!" << endl;
				break;
			case 5:
				if (ContinueOrCancelChoice() == '+') {
					SortByPhoneNumbers(PhoneDirectory, *SIZE);
				}
				else
					cout << "Sort cancelled!" << endl;
				break;

			default:
				cout << "Invalid Choice!" << endl;
				break;
		}
	}
}