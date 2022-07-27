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
	string keyword{};
	int id{};
	char password[MAXPASSLENGTH]{};

	char option = startMenu();

	while (option != 'Q' && option != 'q') {
		switch (option) {
		case 'a':
		case 'A':
			CLS
				cin.ignore();
				setRecordInfo(resource, login, password);
			Records.push_back(login, resource, password);
			Records.saveToFileOne(filename);
			CLS
				Records.printRecord("all");
			cout << endl << "____________________" << endl << endl;
			option = startMenu();
			break;

		case 'e':
		case'E':
			CLS
				Records.clear();
				readAllRecords(filename, resource, login, password, Records);
				if (Records.printRecord("all")) {
					cout << endl << "___________________________________" << endl <<
						"Which record would you like to edit?" << endl <<
						"Enter the record's login, resource or number: ";
					cin >> keyword;
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
						Records.edit_record(login, resource, password, Records.findRecords(keyword), "resource");
						Records.saveToFileAll(filename);
						system("cls");
						Records.printRecord("all");
						break;

					case 'l':
					case 'L':
						cout << "Enter the new login: ";
						cin >> login;
						Records.edit_record(login, resource, password, Records.findRecords(keyword), "login");
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

						Records.edit_record(login, resource, password, Records.findRecords(keyword), "password");
						Records.saveToFileAll(filename);
						CLS
							Records.printRecord("all");
						break;

					default:
						cout << "Error! Wrong option picked." << endl;
						break;
					}
					cout << endl << "____________________" << endl << endl;
					option = startMenu();
				}
				else {
					CLS
						cout << "The file is empty.";
					cout << endl << "____________________" << endl << endl;
					option = startMenu();
				}
				break;

		case 'f':
		case 'F':
			CLS
				cout << "Enter login or resource: ";
			cin >> keyword;
			Records.clear();
			if (readAllRecords(filename, resource, login, password, Records)) {
				Records.printRecord(Records.findRecords(keyword));
			}

			else {
				CLS
					cout << "The file is empty.";
			}

			cout << endl << "____________________" << endl << endl;
			option = startMenu();
			break;
		
		case 's':
		case 'S':
			CLS
				Records.clear();
				if (readAllRecords(filename, resource, login, password, Records)) {
					Records.printRecord("all");
				}

				else {
					CLS
						cout << "The file is empty.";
				}
				cout << endl << "____________________" << endl << endl;
				option = startMenu();
			break;


		case 'd':
		case 'D':
			CLS
				Records.clear();
			if (readAllRecords(filename, resource, login, password, Records)) {
				Records.printRecord("all");
				cout << endl << "___________________________________" << endl <<
					"Which record would you like to delete?" << endl <<
					"Enter the record's number: ";
				cin >> id;
				Records.remove(id);
				Records.printRecord("all");
				Records.saveToFileAll(filename);
			}

			else {
				CLS
					cout << "The file is empty.";
			}

			cout << endl << "____________________" << endl << endl;
			option = startMenu();
			break;

		default:
			cout << "Error! Something went wrong." << endl;
			break;
		}
	}
	CLS
		cout << "Okay, bye!" << endl;
	system("pause");
	return 0;
}