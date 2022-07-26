#include "libs.h"
#include "records.h"
#include "features.h"


int main()
{
	srand(static_cast<unsigned int>(time(NULL)));
	string filename = "records.dat";
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
			CLS
			setRecordInfo(resource, login, password);
			Records.push_back(login, resource, password);
			Records.saveToFileOne(filename);
			break;

		case 'e':
		case'E':
			CLS
			readAllRecords(filename, resource, login, password, Records);
			Records.printRecord("all");
			cout << endl << "___________________________________" << endl <<
				"Which record would you like to edit?" << endl <<
				"Enter the record's number: ";
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
					Records.edit_record(login, resource, password, id, "resource");
					Records.saveToFileAll(filename);
					system("cls");
					Records.printRecord("all");
					break;

				case 'l':
				case 'L':
					cout << "Enter the new login: ";
					cin >> login;
					Records.edit_record(login, resource, password, id, "login");
					Records.saveToFileAll(filename);
					CLS
					Records.printRecord("all");
					break;

				case 'p':
				case 'P':
					option = setPasswordMenu();

					switch (option) {
					case '1':
						setPasswordManually(password);
						break;

					case '2':
						setPasswordAuto(password);
						break;

					case 'q':
						CLS
							startMenu();
						break;

					default:
						CLS
							startMenu();
						break;
					}

					Records.edit_record(login, resource, password, id, "password");
					Records.saveToFileAll(filename);
					CLS
					Records.printRecord("all");
					break;

				default:
					cout << "Error! Wrong option picked." << endl;
					break;
			}
			
			break;

		case 's':
		case 'S':
			CLS
			if (readAllRecords(filename, resource, login, password, Records)) {
				Records.printRecord("all");
			}
			break;


		case 'q':
		case 'Q':
			CLS
			cout << "Okay, bye!" << endl;
			break;

		default:
			cout << "Error! Something went wrong." << endl;
			break;
	}

	system("pause");
	return 0;
}