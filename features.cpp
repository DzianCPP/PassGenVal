#pragma once

#include "features.h"
#include "libs.h"
#include "records.h"

char startMenu()
{
	char option = {};
	cout << "Pick the option:" << endl;
	cout << "a - add a record" << endl;
	cout << "s - show all records" << endl;
	cout << "e - edit a record" << endl;
	cout << "d - delete a record" << endl;
	cout << "q - quit" << endl;
	cin >> option;

	if (option == 'a' || option == 'A' ||
		option == 's' || option == 'S' ||
		option == 'e' || option == 'E' ||
		option == 'd' || option == 'D') {
		return option;
	}

	else if (option == 'q' || option == 'Q') {
		return option;
	}

	else {
		std::system("cls");
		cout << "ERROR! PICK ONE OF THE LISTED OPTIONS" << endl;
		std::system("pause");
		return startMenu();
	}
}



void setRecordInfo(string& resource, string& login, char* password) {
	cout << "Enter the resource: ";
	setResource(resource);

	cout << "Enter your login: ";
	setLogin(login);

	char option = setPasswordMenu();

	switch (option) {
	case '1':
		setPasswordManually(password);
		break;

	case '2':
		setPasswordAuto(password);
		break;

	case 'q':
		startMenu();
		break;

	default:
		startMenu();
		break;
	}
}

void setResource(string& resource) {
	cin >> resource;
}

void setLogin(string& login) {
	cin >> login;
}

char setPasswordMenu() {
	cout << "How do you want to create the password:" << endl <<
		"1 - manually" << endl <<
		"2 - automatically" << endl <<
		"q - quit" << endl;
	char option{};
	cin >> option;
	return option;
}

bool validatePassword(char* password, string mod)
{
	if (strlen(password) < 8 || strlen(password) > 16) {
		if (mod == "manual") {
			cout << "Password is invalid! It must be 8-16 symbols" << endl;
		}
		return false;
	}

	int upperCount = 0;
	for (int i = 0; i <= strlen(password) - 1; i++) {
		if (isupper(password[i])) {
			upperCount++;
		}
	}
	if (!upperCount) {
		if (mod == "manual") {
			cout << "Error! The password doesn't have upper case letters!" << endl;
		}
		return false;
	}

	int lowerCount = 0;
	for (int i = 0; i <= strlen(password) - 1; i++) {
		if (islower(password[i])) {
			lowerCount++;
		}
	}
	if (!lowerCount) {
		if (mod == "manual") {
			cout << "Error! The password doesn't have lower case letters!" << endl;
		}
		return false;
	}

	int numCount = 0;
	for (int i = 0; i <= strlen(password) - 1; i++) {
		if (isdigit(password[i])) {
			numCount++;
		}
	}
	if (!numCount) {
		if (mod == "manual") {
			cout << "Error! The password doesn't have numbers." << endl;
		}
		return false;
	}

	int specialCount = 0;
	for (int i = 0; i <= strlen(password) - 1; i++)
	{
		if (password[i] == 33
			|| password[i] == 35 || password[i] == 36
			|| password[i] == 37 || password[i] == 38
			|| password[i] == 40 || password[i] == 41
			|| password[i] == 42 || password[i] == 43
			|| password[i] == 45 || password[i] == 61
			|| password[i] == 64 || password[i] == 94 || password[i] == 95)
		{
			specialCount++;
		}
		if (mod == "auto") {
			if (password[i] == 34 || password[i] == 39
				|| password[i] == 40 || password[i] == 41
				|| password[i] == 44 || password[i] == 46
				|| password[i] == 47 || password[i] == 58
				|| password[i] == 59 || password[i] == 60
				|| password[i] == 62 || password[i] == 63
				|| password[i] == 91 || password[i] == 92
				|| password[i] == 93 || password[i] == 96) {
				password[i] = rand() % 89 + 33;
				i--;
			}
		}
	}

	if (!specialCount)
	{
		return false;
	}

	return true;
}

char* setPasswordManually(char* password) {
	cin >> password;
	if (validatePassword(password, "manual")) {
		return password;
	}

	else {
		cout << "Error! Password is not validated. Try again?" << endl <<
			"Y - yes" << endl <<
			"N - no, quit" << endl;
		char option{};
		cin >> option;
		if (option == 'Y' || option == 'y') {
			return setPasswordManually(password);
		}

		else {
			cout << "Bye" << endl;
			return NULL;
		}
	}
}

int setPasswordSize() {
	int pass_size = rand() % 16 + 1;

	if (pass_size < 9 || pass_size > 17) {
		return setPasswordSize();
	}

	else {
		return pass_size;
	}
}

char* setPasswordAuto(char* password) {
	int pass_size = setPasswordSize();
	
	for (int i = 0; i < pass_size; i++)
	{
		password[i] = rand() % 89 + 33;
	}
	password[pass_size] = '\0';

	if (validatePassword(password, "auto"))
	{
		return password;
	}

	else
	{
		return setPasswordAuto(password);
	}
}



void readInfo(string filename, char* value, ifstream& fin) {
	fin.getline(value, 100);
}

bool readInfo(string filename, string& value, ifstream& fin) {
	string value_temp;
	getline(fin, value_temp);
	if (value_temp == "" || value_temp == "\n") {
		return false;
	}
	
	else {
		value = value_temp;
		return true;
	}
}

bool readAllRecords(string filename, string& resource, string& login, char* password, records& Records) {
	ifstream fin(filename);
	if (!fin.is_open()) {
		cout << "Error! File not working." << endl;
		return false;
	}

	char toSkip[2]{};
	for (; ;) {
		if (!(readInfo(filename, resource, fin))) {
			break;
		}
		readInfo(filename, login, fin);
		readInfo(filename, password, fin);
		Records.push_back(login, resource, password);
		if (fin.eof()) {
			break;
		}
	}
	fin.close();

	return true;
}