#include "libs.h"
#include "records.h"
#include "features.h"


int main()
{
	srand(static_cast<unsigned int>(time(NULL)));
	string filename = "Records.txt";
	const int MAXPASSLENGTH = 17;
	records Records;
	string resource{};
	string login{};
	int id;
	char password[MAXPASSLENGTH]{};

	char option = startMenu();

	switch (option) {
		case 'a':
		case 'A':
			setRecordInfo(resource, login, password);
			Records.push_back(login, resource, password);
			Records.saveToFileAll("records.txt");
			break;

		case 'e':
		case'E':
			readAllRecords(filename, resource, login, password, Records);
			Records.printRecord("all");
			cout << endl << "___________________________________" << endl <<
				"Which record would you like to edit?" << endl <<
				"Enter the record's id: ";
			cin >> id;
			cout << "What do you need to change?" << endl <<
				"R - resource" << endl <<
				"L - login" << endl <<
				"P - password" << endl <<
				"q - quit" << endl;
			cin >> option;
			switch (option) {
				case 'r':
				case 'R':
					cout << "Enter the new resource: ";
					cin >> resource;
					Records.edit_record(login, resource, password, id);
					Records.saveToFileAll(filename);
					std:system("cls");
					Records.printRecord("all");
					break;

				default:
					cout << "Error! Wrong option picked." << endl;
					break;
			}

		case 's':
		case 'S':
			if (readAllRecords(filename, resource, login, password, Records)) {
				Records.printRecord("all");
			}
			break;

		default:
			cout << "Error! Something went wrong." << endl;
			break;
	}

	system("pause");
	return 0;
}