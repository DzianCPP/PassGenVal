#include "libs.h"
#include "records.h"
#include "features.h"


int main()
{
	srand(static_cast<unsigned int>(time_t(NULL)));
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
			break;

		default:
			cout << "Error! Something went wrong." << endl;
			break;
	}
	return 0;
}