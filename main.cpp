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
			cout << endl << "___________________________________" << endl <<
				"Which record would you like to edit?" << endl <<
				"Enter the record's id: ";
			cin >> option;
			cout << "What do you need to change?" << endl <<
				"R - resource" << endl <<
				"L - login" << endl <<
				"P - password" << endl <<
				"q - quit" << endl;
			char option2{};
			cin >> option2;
			switch (option2) {
				case 'r':
				case 'R':
					cout << "Enter the new resource: ";
					cin >> resource;

					break;

				default:
					cout << "Error! Wrong option picked." << endl;
					break;
			}

		default:
			cout << "Error! Something went wrong." << endl;
			break;
	}
	return 0;
}